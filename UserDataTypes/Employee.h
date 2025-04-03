#pragma once
#include <string>

class Employee {
public:
    void Read();
    void Write();

private:

    static std::array<float, 3> calculateIncomes(float wage, float totalHours, float TAX);
    std::string name;
    char initial;
    short age;
    unsigned int zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
    float totalHours = 0;

    static const float TAX; // Declare tax as a static constant
};
