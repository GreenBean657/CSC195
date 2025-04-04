#include "Employee.h"

#include <array>
#include <iostream>
#include <format>

const float Employee::TAX = 0.15;

void Employee::Read() {
    std::cout << "Enter First Name: ";
    std::cin >> name;

    std::cout << "Enter Initial of last name: ";
    std::cin >> initial;

    std::cout << "Enter Age: ";
    std::cin >> age;

    std::cout << "Enter Zipcode: ";
    std::cin >> zipcode;

    std::cout << "Enter hourly wage: ";
    std::cin >> wage;

    std::cout << "Enter number of days worked (max 7): ";
    std::cin >> daysWorked;

}

void Employee::Write() {
    std::array<float, 3> incomes = calculateIncomes(wage, totalHours, TAX);

    std::cout << std::format(R"(
    Employee Payroll Summary
    ------------------------
    Name: {} {}.
    Age: {} (Adult: {})
    ZipCode: {}
    Hourly Wage: ${:.2f}
    Total Hours Worked: {}
    Gross Income: ${:.2f}
    Tax Amount: ${:.2f}
    Net Income: ${:.2f}
    )",
    name, initial,
    age, ((age >= 18) ? "Yes" : "No"),
    zipcode,
    wage,
    totalHours,
    incomes[0],
    incomes[1],
    incomes[2]
    );
}

std::array<float, 3> Employee::calculateIncomes(const float wage, const float totalHours, const float TAX) {
    std::array<float, 3> incomes{};

    incomes[0] = totalHours * wage;
    incomes[1] = incomes[0] * TAX;
    incomes[2] = incomes[0] - incomes[1];

    return incomes;
}

