#include "Game2.h"
#include <conio.h>
#include <iostream>


void Game2::draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
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
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Wynik z Game2: " << nTail * 100 << endl;
}

void Game2::input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'j':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'l':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'i':
            if (dir != DOWN)
                dir = UP;
            break;
        case 'k':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'z':
            gameOver = true;
            break;
        }
    }
}