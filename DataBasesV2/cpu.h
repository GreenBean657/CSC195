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

    std::string getSocket() const {
        return this->socket;
    }

    int getCoreCount() const {
        return this->coreCount;
    }

    /**
    * @brief Set the Core Count, based on a string.
    * UNPROTECTED - Will except if the string is not a valid revision.
    * CATCH the exception in the calling function.
    */
    void setCoreCount(std::string set_able_core_count) {
        this->coreCount = std::stoi(set_able_core_count);
    }

    void setCoreCountLoadable(int coreCount) {
        this->coreCount = coreCount;
    }

protected:
    std::string socket;
    int coreCount;

};


#endif