#pragma once
#include "Object.h"

class Obstacle : public Object {
public:
    using Object::Object;
    using Object::getX;
    using Object::getY;
    void info(int n);
};
