//
// Created by GreenBean on 4/19/25.
//

#ifndef GPU_H
#define GPU_H

#include "computerpart.h"
#include <ui_gpu_window.h>

enum CONNECTION_STANDARD {
    PCI,
    PCIe,
    AGP
};


/**
 * @class GPU
 * @brief Represents a GPU as a computer part.
 */
class GPU : public ComputerPart {

public:
    Ui::GPUWidget ui{};
    GPU(): ComputerPart() {
        connectionStandard = PCIe;
        PCIeRevision = 3;
        revisionTable = {PCI, PCIe, AGP};
    } //CONSTRUCTOR
    void widgetLoader(QWidget *widget) override;

    /**
     * @brief Set the PCIe revision, based on a string.
     * UNPROTECTED - Will except if the string is not a valid revision.
     * CATCH the exception in the calling function.
     */
    void setPCIeRevision(const QString&);

    /**
     * @brief Change the PCIe slot, based on an index.
     */
    void setPCIeSlot(int);
private:
    CONNECTION_STANDARD connectionStandard;
    int PCIeRevision;
    std::array<CONNECTION_STANDARD, 3> revisionTable{};
};



#endif //GPU_H
