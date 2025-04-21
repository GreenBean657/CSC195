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

    void setPCIeRevision(QString revision);
    void setPCIeSlot(int);

    void setCoreCount(QString coreCount);
    void setSocket(QString socket);

    void DDR_R_Change(int index);
    void changeFreq(QString freq);
    void changeCL(QString cl);
};



#endif //EDITORWIDGET_H
