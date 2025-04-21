//
// Created by GreenBean on 4/19/25.
//

#include "gpu.h"


void GPU::widgetLoader(QWidget *widget) {
    ui.setupUi(widget);
    if (const auto child = widget->findChild<QLineEdit *>("GPU_PCIe_Revision")) {
        child->setText(QString::number(PCIeRevision));
    }
    if (const auto child = widget->findChild<QComboBox *>("GPU_Connector")) {
        if (connectionStandard == PCI) {
            child->setCurrentIndex(0);
        } else if (connectionStandard == PCIe) {
            child->setCurrentIndex(1);
        } else if (connectionStandard == AGP) {
            child->setCurrentIndex(2);
        }
    }
}



void GPU::setPCIeRevision(const QString& revision) {
    //Spooky!
    try {
        const int temp_PCIeRevision = std::stoi(revision.toStdString());
        if (temp_PCIeRevision < 1 || temp_PCIeRevision > 5) {
            throw std::out_of_range("Invalid PCIe revision");
        }
        PCIeRevision = temp_PCIeRevision;

    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid PCIe revision");
    }
}

void GPU::setPCIeSlot(const int slot) {
    try {
        GPU::connectionStandard = revisionTable[slot];
    } catch (std::out_of_range &e) {
        qDebug() << "Error: " << e.what();
    }
}