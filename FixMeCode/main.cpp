#include <iostream>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;


int main() {
    vector<Shape*> shapes;
    auto* circleObj = new Circle(1.0f);
    circleObj->SetRadius(3.0f);
    auto* rectObj = new Rectangle(4.0f, 5.0f);
    shapes.push_back(circleObj);
    shapes.push_back(rectObj);
    for (const auto & shape : shapes) {
        cout << "Area: " << shape->Area() << endl;
        if (const auto* circle = dynamic_cast<Circle*>(shape); circle != nullptr) {
            cout << "Radius: " << circle->GetRadius() << endl;
        }
        cout << "-============-" << endl;
    }

    for (const Shape* obj : shapes) {
        delete obj;
    }
    return 0;
}