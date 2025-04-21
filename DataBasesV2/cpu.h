#include "computerpart.h"
#include <ui_cpu_window.h>


#ifndef CPU_H
#define CPU_H
/**
 * @class CPU
 * @brief Represents a CPU as a computer part.
 */
class CPU : public ComputerPart {

public:
    Ui::CPUWidget ui{};
    CPU() : ComputerPart() {
        coreCount = 0;
        socket = "Unknown";
    } // Constructor
    void widgetLoader(QWidget *widget) override;
    /**
    * @brief Set the CL Latency, based on a string.
    */
    void setSocket(std::string setablesocket) {
        this->socket = setablesocket;
    }

    /**
    * @brief Set the Core Count, based on a string.
    * UNPROTECTED - Will except if the string is not a valid revision.
    * CATCH the exception in the calling function.
    */
    void setCoreCount(std::string set_able_core_count) {
        if (coreCount >= 0) {
            this->coreCount = std::stoi(set_able_core_count);
        } else {
            throw std::invalid_argument("Core count must be greater than 0");
        }
    }

protected:
    std::string socket;
    int coreCount;

};


#endif