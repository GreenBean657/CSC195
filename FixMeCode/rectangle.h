//
// Created by GreenBean on 4/23/25.
//
#pragma once
#include "shape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle : public Shape {
public:
    explicit Rectangle(const float w, const float h) {
        m_width = w;
        m_height = h;
    }
    float Area() override {
      return m_width * m_height;
    }
private:
    float m_width;
    float m_height;
};



#endif //RECTANGLE_H
