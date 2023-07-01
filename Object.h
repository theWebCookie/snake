#pragma once
class Object {
private:
    int x, y;
public:
    Object(int width, int height);
    virtual int getX();
    virtual int getY();
    virtual void info(int n);
};
