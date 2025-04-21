//
// Created by GreenBean on 4/19/25.
//

#include "cpu.h"


void CPU::widgetLoader(QWidget *widget) {
    ui.setupUi(widget);
    if (const auto child = widget->findChild<QLineEdit*>("CPU_ChangeCores")) {
        child->setText(QString::number(coreCount));
    }
    if (const auto child = widget->findChild<QLineEdit*>("CPU_ChangeSocket")) {
        child->setText(QString::fromStdString(socket));
    }
}

