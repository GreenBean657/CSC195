

#include "cpuwidget.h"

#include "cpu.h"


void CPUWidget::setSocket(QString socket) {
    auto computerPart = dynamic_cast<CPU *>(part);
    computerPart->setSocket(socket.toStdString());
}


void CPUWidget::setCoreCount(QString count) {
    auto computerPart = dynamic_cast<CPU *>(part);
    try {
        computerPart->setCoreCount(count.toStdString());
    } catch (std::exception &e) {
        QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(QObject::sender());
        lineEdit->setText("");
    }
}


//void GPUWidget::setPCIeSlot(const int slot) {
//    if (QObject::sender()->objectName() == "GPU_Connector") {
//        auto computerPart = dynamic_cast<GPU *>(part);
//        computerPart-> setPCIeSlot(slot);
//    }
//}