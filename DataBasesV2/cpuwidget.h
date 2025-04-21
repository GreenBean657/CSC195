//
// Created by GreenBean on 4/19/25.
//

#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QtWidgets/QWidget>
#include "computerpart.h"

class CPUWidget: public QWidget {
    Q_OBJECT

 public:
    ComputerPart *part = nullptr;
    CPUWidget(QWidget *parent = nullptr): QWidget(parent) {}

    public slots:
      void setSocket(QString socket);
      void setCoreCount(QString coreCount);
};



#endif