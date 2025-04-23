//
// Created by GreenBean on 4/23/25.
//
#pragma once
#ifndef SHAPE_H
#define SHAPE_H



class Shape {
public:
    virtual ~Shape() = default;
    virtual float Area() = 0;
};


#endif //SHAPE_H
