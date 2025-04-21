#ifndef RAM_H
#define RAM_H

#include "computerpart.h"
#include <ui_ram_window.h>

enum DDR_REVISION {
    DDR1,
    DDR2,
    DDR3,
    DDR4,
    DDR5,
};


/**
 * @class RAM
 * @brief Represents a RAM as a computer part.
 */
class RAM : public ComputerPart {

public:
    Ui::RAMWidget ui{}; // Declare the ui member
    RAM() : ComputerPart() {
        ddrRevision = DDR3;
        freq = 1600;
        clLatency = 9;
        revisionTable = {DDR1, DDR2, DDR3, DDR4, DDR5};

    } // Constructor
    void widgetLoader(QWidget *widget) override;
    /**
 * @brief Set the frequency, based on a string.
 * UNPROTECTED - Will except if the string is not a valid revision.
 * CATCH the exception in the calling function.
 */
    void setFreq(std::string freq);
    /**
 * @brief Set the CL Latency, based on a string.
 * UNPROTECTED - Will except if the string is not a valid revision.
 * CATCH the exception in the calling function.
 */
    void setClLatency(std::string clLatency);

    /**
     * Set the DDR based on a table index.
     * @param level Index.
     */
    void setDDR(int level);



private:
    DDR_REVISION ddrRevision;
    int freq;
    int clLatency;
    std::array<DDR_REVISION, 5> revisionTable{};
};

#endif // RAM_H