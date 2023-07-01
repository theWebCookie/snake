#pragma once
class Snake {
private:
    int x, y;
public:
    Snake(int width, int height);
    void setX(int X);
    void setY(int Y);
    int getX();
    int getY();
};
