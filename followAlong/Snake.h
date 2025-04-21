
#pragma once
#include "Animal.h"

class Snake : public Animal {
public:
    Snake() {
        m_limbs = 0;
        m_has_venom = false;
        std::cout << "Snake Constructor" << std::endl;
    }
    void Speak() override;
protected:
    bool m_has_venom;
};
