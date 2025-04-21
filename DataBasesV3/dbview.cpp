//
// Created by GreenBean on 4/19/25.
//

#include "dbview.h"

#include <iostream>
#include <ostream>
#include <QtGui/QStandardItemModel>
#include "computerpart.h"
#include "gpu.h"

DbView::DbView(QWidget *parent) : QListView(parent) {
  auto *model = new QStandardItemModel(0, 1, this);
  QListView::setModel(model);
}

void DbView::createNew() {
  auto *model = dynamic_cast<QStandardItemModel *>(QListView::model());
  auto *part = new GPU();
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
}


