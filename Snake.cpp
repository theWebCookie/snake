#include "Snake.h"

Snake::Snake(int width, int height) {
    x = width / 2;
    y = height / 2;
}

void Snake::setX(int X) {
    x = X;
}

void Snake::setY(int Y) {
    y = Y;
}

int Snake::getX() {
    return x;
}

int Snake::getY() {
    return y;
}
