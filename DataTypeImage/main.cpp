#include <format>
#include <iostream>

class Building {
public:
    /**
    * @brief Adjusts the population of the building.
    * @param amount Amount to adjust the population by
    */
    void adjustPopulation(const int amount) {
        this->setPopulation(this->population + amount);
    }

    /**
     * Set the population for the building,
     * @param newPopulation New population to set.
     */
    void setPopulation(const int newPopulation) {
        if (newPopulation < 0) {
            std::cerr << "Population cannot be negative" << std::endl;
            return;
        }
        if (newPopulation > maxPopulation) {
            std::cerr << "Population beyond max!" << std::endl;
            return;
        }
        this->population = newPopulation;
    }

    /**
     * Set the power for the building.
     * @param powerState TRUE: Building has power, FALSE: Building has no power
     */
    void setPowerState(const bool powerState) {
        this->hasPower = powerState;
    }


    void setName(const std::string name) {
        this->name = name;
    }

    std::string getName() {
        return this->name;
    }

    unsigned short getPopulation() const {
        return this->population;
    }

    unsigned short getMaxPopulation() const {
        return this->maxPopulation;
    }

    bool getPowerState() {
        return this->hasPower;
    }


    std::string toString() {
    return std::format(R"(
    {} Status:
    -----------------
    Population: {}
    Max Capacity: {}
    Has Power: {}
    )",
    this-> name,
    this->population,
    this->maxPopulation,
    (this->hasPower ? "Yes" : "No"));
    }

private:
    unsigned short population = 0;
    unsigned const short maxPopulation = 1000;
    bool hasPower = true;
    std::string name = "Building";
};


class BasketBalLCourt {
public:
    /**
     * Start the game.
     */
    void startGame() {
        if (inUse) {
            std::cerr << "Game already in progress!" << std::endl;
            return;
        }
        if (durability <= 0.0f) {
            std::cerr << "Court is broken!" << std::endl;
            return;
        }
        inUse = true;
        ballCount = 1;
        plrCount = 10;
    }

    /**
     * Stop the game.
     */
    void stopGame() {
        inUse = false;
        ballCount = 0;
        plrCount = 0;
        durability = durability - 10.8f;
    }

    /**
     * Fix the court.
     */
    void fixCourt() {
        durability = 100.0f;
    }

private:
    bool inUse = false;
    unsigned short ballCount = 0;
    unsigned short plrCount = 0;
    float durability = 100.0f;
};


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Building building = Building();
    building.adjustPopulation(20);
    building.adjustPopulation(-20);
    building.adjustPopulation(0);
    building.setName("Cool Building");
    std::cout << "Population: " << building.getPopulation() << std::endl;
    std::cout << building.toString() << std::endl;

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.