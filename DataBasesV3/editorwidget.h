//
// Created by GreenBean on 4/19/25.
//

#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QtWidgets/QWidget>
#include "computerpart.h"

class EditorWidget: public QWidget {
   Q_OBJECT

public:
    ComputerPart *part = nullptr;
    EditorWidget(QWidget *parent = nullptr): QWidget(parent) {}

public slots:
  void setSpecializedCheckbox(Qt::CheckState);
};



#endif //EDITORWIDGET_H
