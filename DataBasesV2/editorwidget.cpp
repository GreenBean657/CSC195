//
// Created by GreenBean on 4/19/25.
//

#include "editorwidget.h"
#include "gpu.h"
#include "cpu.h"
#include "ram.h"

void EditorWidget::setPCIeRevision(const QString revision) {
    try {
      auto computerPart = dynamic_cast<GPU *>(part);
      computerPart->setPCIeRevision(revision);
    } catch (std::exception &e) {
      QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(QObject::sender());
      lineEdit->setText("");
    }
}

void EditorWidget::setPCIeSlot(const int slot) {
    auto computerPart = dynamic_cast<GPU *>(part);
    computerPart-> setPCIeSlot(slot);
}

void EditorWidget::setCoreCount(QString coreCount) {
  try {
    auto computerPart = dynamic_cast<CPU *>(part);
    computerPart->setCoreCount(coreCount.toStdString());
  } catch (std::exception &e) {
    QLineEdit *line_edit = dynamic_cast<QLineEdit *>(QObject::sender());
    line_edit->setText("");
  }
}

void EditorWidget::setSocket(QString socket) {
  auto computerPart = dynamic_cast<CPU *>(part);
  computerPart->setSocket(socket.toStdString());
}

void EditorWidget::changeFreq(QString freq) {
  try {
    auto computerPart = dynamic_cast<RAM *>(part);
    computerPart->setFreq(freq.toStdString());
  } catch (std::exception &e) {
    QLineEdit *line_edit = dynamic_cast<QLineEdit *>(QObject::sender());
    line_edit->setText("");
  }
}

void EditorWidget::changeCL(QString cl) {
  try {
    auto computerPart = dynamic_cast<RAM *>(part);
    computerPart->setClLatency(cl.toStdString());
  } catch (std::exception &e) {
    QLineEdit *line_edit = dynamic_cast<QLineEdit *>(QObject::sender());
    line_edit->setText("");
  }
}

void EditorWidget::DDR_R_Change(int index) {
  auto computerPart = dynamic_cast<RAM *>(part);
  try {
    computerPart->setDDR(index);
  } catch (std::exception &e) {
    qDebug() << e.what();
  }
}
