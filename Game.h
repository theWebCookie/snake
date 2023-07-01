#pragma once
#include <vector>
#include <string>
#include "Snake.h"
#include "Object.h"
#include "Obstacle.h"
#include "Food.h"

using namespace std;

class Game {
protected:
    bool gameOver;
    int width = 25;
    int height = 20;
    enum Direction { LEFT, RIGHT, UP, DOWN, NONE };
    Direction dir = NONE;
    int tailX[50], tailY[50];
    int nTail;
    Snake snake = Snake(width, height);
    int x;
    int y;
    int speed;
    bool obstacleAdded;
    int nF;
    int nO;
    vector<Object*> obstacles;
    Object* food = new Food(width, height);

public:
    string nick;
    Game();
    virtual void draw();
    virtual void input();
    void logic();
    void run();
    void save();
};

