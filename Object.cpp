#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Object::Object(int width, int height) {
    x = rand() % width;
    y = rand() % height;
}

int Object::getX() {
    return x;
}

int Object::getY() {
    return y;
}

void Object::info(int n) {
    cout << "Przegrana!" << endl;
}