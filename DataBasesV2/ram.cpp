//
// Created by GreenBean on 4/19/25.
//

#include "ram.h"


void RAM::widgetLoader(QWidget *widget) {
    ui.setupUi(widget);
    if (const auto child = widget->findChild<QLineEdit*>("RAM_CL")) {
        child-> setText(QString::number(clLatency));
    }
    if (const auto child = widget->findChild<QLineEdit*>("RAM_Freq")) {
        child-> setText(QString::number(freq));
    }
    if (const auto child = widget->findChild<QComboBox*>("RAM_Revision")) {
        if (ddrRevision == DDR1) {
            child->setCurrentIndex(0);
        } else if (ddrRevision == DDR2) {
            child->setCurrentIndex(1);
        } else if (ddrRevision == DDR3) {
            child->setCurrentIndex(2);
        } else if (ddrRevision == DDR4) {
            child->setCurrentIndex(3);
        } else if (ddrRevision == DDR5) {
            child->setCurrentIndex(4);
        }
    }
}

void RAM::setFreq(std::string freq) {
    int freq_int = std::stoi(freq);
    if (freq_int < 0) {
        throw std::invalid_argument("Frequency must be greater than 0");
    }
    this->freq = freq_int;
}

void RAM::setDDR(int ddr) {
    this->ddrRevision = this->revisionTable[ddr];

}

void RAM::setClLatency(std::string clLatency) {
    int cl_int = std::stoi(clLatency);
    if (cl_int < 0) {
        throw std::invalid_argument("Frequency must be greater than 0");
    }
    this->clLatency = cl_int;
}
