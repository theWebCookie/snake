#pragma once
#include "Object.h"

class Food : public Object {
public:
    using Object::Object;
    using Object::getX;
    using Object::getY;
    void info(int n);
};
