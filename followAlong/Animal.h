#pragma once
#include <stdexcept>
#include <iostream>

class Animal {
public:
    Animal(int limbs = 4) {
        if (limbs < 4) {
            throw std::invalid_argument("limbs must be greater than 4");
        }
        m_limbs = limbs;
        m_ptr = new int(25);
        std::cout << "Animal Constructor" << std::endl;
    }

    virtual ~Animal() {
        // Destructor
        delete m_ptr;
    };
    virtual void Speak() = 0; //Pure Virtual Function
    int getLimbs() {return m_limbs;}
    void setLimbs(int limbs) {m_limbs = limbs;}

protected:
    int m_limbs;

    int* m_ptr = nullptr;
};
