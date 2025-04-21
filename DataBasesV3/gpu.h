//
// Created by GreenBean on 4/19/25.
//

#ifndef GPU_H
#define GPU_H

#include "computerpart.h"
#include <ui_testwindow.h>

class GPU : public ComputerPart {

public:
    Ui::GPUWidget ui{};
    GPU(): ComputerPart("GPU", Sockets::PCIe) {}

    void widgetLoader(QWidget *widget) override;

    bool setState = false;
};



#endif //GPU_H
