#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include "Game.h"

using namespace std;

Game::Game() {
    nTail = 0;
    nF = 1;
    nO = 2;
    x = snake.getX();
    y = snake.getY();
    speed = 100;
    nick = "";
    gameOver = false;
    obstacleAdded = true;
    obstacles.push_back(new Obstacle(width, height));
    obstacles.push_back(new Obstacle(width, height));
    for (int i = 0; i < obstacles.size(); i++) {
        if (obstacles.at(i)->getX() == food->getX() || obstacles.at(i)->getY() == food->getY()) {
            food = new Food(width, height);
        }
    }
    for (int i = 0; i < 50; i++) {
        tailX[i] = 0;
        tailY[i] = 0;
    }
}

void Game::draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "|";
            }
            if (i == snake.getY() && j == snake.getX()) {
                cout << "O";
            }
            else if (i == obstacles.at(0)->getY() && j == obstacles.at(0)->getX() || i == obstacles.at(1)->getY() && j == obstacles.at(1)->getX()) {
                cout << "X";
            }
            else if (i == food->getY() && j == food->getX()) {
                cout << "F";
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) {
                    cout << " ";
                }
            }
            if (j == width - 1) {
                cout << "|";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "Wynik: " << nTail * 100 << endl;
}


void Game::input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if(dir != RIGHT)
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snake.getX();
    tailY[0] = snake.getY();

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
        if (tailX[i] == x && tailY[i] == y) {
            food->info(nF);
            obstacles.at(0)->info(nO);
            gameOver = true;
        }
    }


    switch (dir) {
    case LEFT:
        x--;
        snake.setX(x);
        break;
    case RIGHT:
        x++;
        snake.setX(x);
        break;
    case UP:
        y--;
        snake.setY(y);
        break;
    case DOWN:
        y++;
        snake.setY(y);
        break;
    case NONE:
        break;
    }

    if (snake.getY() == food->getY() && snake.getX() == food->getX()) {
        nTail++;
        if (speed == 10) {
            speed = 1;
        }
        else if (speed > 10) {
            speed -= 10;
        }
        food = new Food(width, height);
        nF++;
    }

    if (snake.getX() < 0 || snake.getX() > width - 1 || snake.getY() < 0 || snake.getY() > height - 1 || (snake.getX() == obstacles.at(0)->getX() && snake.getY() == obstacles.at(0)->getY()) || (snake.getX() == obstacles.at(1)->getX() && snake.getY() == obstacles.at(1)->getY())) {
        food->info(nF);
        obstacles.at(0)->info(nO);
        gameOver = true;
    }

    if (nTail % 2 == 0 && nTail != 0 && !obstacleAdded) {
        if (food->getY() != obstacles.at(0)->getY() || food->getX() != obstacles.at(0)->getX() || food->getY() != obstacles.at(1)->getY() || food->getX() != obstacles.at(1)->getX()) {
            for (int i = 0; i < obstacles.size(); i++) {
                obstacles.push_back(new Obstacle(width, height));
                obstacles.erase(obstacles.begin());
                nO++;
            }
        }
        obstacleAdded = true;
    }
    else if (nTail % 2 != 0 && obstacleAdded) {
        obstacleAdded = false;
    }
}

void Game::save() {
    ofstream file("wyniki.txt", ios::app);

    if (file) {
        file << nick << " " << nTail * 100 << endl;
        file.close();
    }
    else {
        cout << "Nie uda³o siê otworzyæ pliku z wynikami" << endl;
    }
}

void Game::run() {
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(speed);
    }
    save();
}