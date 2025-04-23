//
// Created by GreenBean on 4/23/25.
//
#pragma once
#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : public Shape {
public:
    explicit Circle(const float r) {
       this->SetRadius(r);
    };
    float Area() override {
        return 3.14f * m_radius * m_radius;
    }
    void SetRadius(const float radius) {
        m_radius = radius;
    }
    float GetRadius() const {
        return m_radius;
    }

private:
    float m_radius;
};



#endif //CIRCLE_H
