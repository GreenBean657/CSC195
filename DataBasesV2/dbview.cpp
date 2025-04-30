#include "dbview.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <QtGui/QStandardItemModel>
#include "computerpart.h"
#include "gpu.h"
#include "cpu.h"
#include "ram.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>

void DbView::save() {
  QJsonArray array;
  const auto *dbList = dynamic_cast<QStandardItemModel *>(this->model());

  for (int row = 0; row < dbList->rowCount(); ++row) {
    QJsonObject object;
    try {
      if (dynamic_cast<GPU *>(dbList->item(row))) {
        GPU* gpu = dynamic_cast<GPU*>(dbList->item(row));

        object["type"] = "GPU";
        object["pcieRevision"] = gpu->getPCIeRevision_Loadables();
        object["connectionStandard"] = gpu->getConnectionStandard_Loadables();


      } else if (dynamic_cast<CPU *>(dbList->item(row))) {
        CPU* cpu = dynamic_cast<CPU*>(dbList->item(row));

        object["type"] = "CPU";
        object["coreCount"] = cpu->getCoreCount();
        object["socket"] = QString::fromStdString(cpu->getSocket());

      } else if (dynamic_cast<RAM *>(dbList->item(row))) {
        RAM* ram = dynamic_cast<RAM*>(dbList->item(row));
        object["type"] = "RAM";
        object["ddrRevision"] = ram->getDDR();
        object["freq"] = ram->getFreq();
        object["clLatency"] = ram->getClLatency();

      } else {
        throw std::invalid_argument("Invalid part type...");
      }
    } catch (std::exception &e) {
      QMessageBox::warning(this, "Error", "Could not write!");
      return;
    }
    array.append(object);
  }
  QJsonObject main;
  main["parts"] = array;
  QJsonDocument document(main);

  std::string jsonData = document.toJson(QJsonDocument::Indented).toStdString();
  std::ofstream outFile("saved.txt");

  outFile << jsonData;
  outFile.close();

}

void DbView::load() {

  std::ifstream inFile("saved.txt");
  if (!inFile) {
    QMessageBox::warning(this, "Error", "Could not open file with ifstream!");
    return;
  }

  // Read file contents into a std::string
  std::string fileContents((std::istreambuf_iterator<char>(inFile)),
                            std::istreambuf_iterator<char>());
  inFile.close();

  // Convert std::string to QByteArray
  QByteArray data = QByteArray::fromStdString(fileContents);
  QJsonDocument extracted_file(QJsonDocument::fromJson(data));

  if (extracted_file.isNull()) {
    QMessageBox::warning(this, "Error", "Invalid contents, you sure you opened the right file?");
    return;
  }

  QStandardItemModel *model = dynamic_cast<QStandardItemModel *>(this->model());
  model->removeRows(0, model->rowCount());

  QJsonArray array = extracted_file.object()["parts"].toArray();

  for (const QJsonValue &item : array) {
    QJsonObject object = item.toObject();
    QString partType = object["type"].toString();
    if (partType == "GPU") {
      auto part = new GPU();
      part->setPCIeRevision_Loadables(object["pcieRevision"].toInt());
      part->setConnectionStandard_Loadables(object["connectionStandard"].toInt());
      model->appendRow(part);
    } else if (partType == "CPU") {
      CPU *part = new CPU();
      part->setSocket(object["socket"].toString().toStdString());
      part->setCoreCountLoadable(object["coreCount"].toInt());
      model->appendRow(part);
    } else if (partType == "RAM") {
      RAM *part = new RAM();
      part->setFreq_LOADABLES(object["freq"].toInt());
      part->setCLLatency_LOADABLES(object["clLatency"].toInt());
      part->setDDR(object["ddrRevision"].toInt());
      model->appendRow(part);
    } else {
      throw std::invalid_argument("Invalid part type...");
    }
  }

  currentChanged(model->index(0, 0), model->index(0, 0));
}


DbView::DbView(QWidget *parent) : QListView(parent) {
  auto *model = new QStandardItemModel(0, 1, this);
  QListView::setModel(model);
}

void DbView::createNewGPU() {
  auto *model = dynamic_cast<QStandardItemModel *>(QListView::model());
  auto *part = new GPU();
  model->appendRow(part);
}

void DbView::createNewCPU() {
  auto *model = dynamic_cast<QStandardItemModel *>(QListView::model());
  auto *part = new CPU();
  model->appendRow(part);
}

void DbView::createNewRAM() {
  auto *model = dynamic_cast<QStandardItemModel *>(QListView::model());
  auto *part = new RAM();
  model->appendRow(part);
}

inline ComputerPart *DbView::itemFromIndex(const QModelIndex &index) {
  return dynamic_cast<ComputerPart *>(dynamic_cast<QStandardItemModel *>(QListView::model())->itemFromIndex(index));
}

void DbView::currentChanged(const QModelIndex &current, const QModelIndex &previous) {
  ComputerPart *part = itemFromIndex(current);
  if (part == nullptr) {
    return;
  }
  qDeleteAll(widget->children());
  widget->part = part;
  part->widgetLoader(widget);
}

void DbView::deleteSelected() {
  auto selected = currentIndex();
  if (selected.isValid()) {
    model()->removeRow(selected.row());
  }
  if (model()->rowCount() <= 0) {
  // Delete displayed entry when widget is empty.
    qDeleteAll(widget->children());
  }
}


