#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Game2.h"

using namespace std;

void read(string &n, int &s) {
    ifstream myfile("wyniki.txt");
    if (myfile.is_open())
    {
        string header;
        myfile >> header;
        string nick;
        int score;
        while (myfile >> nick >> score)
        {
            if (score > s) {
                n = nick;
                s = score;
            }
        }
        myfile.close();
    }
}

int main()
{
    string n;
    int s;
    read(n, s);
    srand((unsigned int)time(NULL));

    Game2 game;

    cout << R"(                                          
                                                                   
                                                __
         _____             _                   {0O}  
        / ____|           | |                  \__/    
       | (___  _ __   __ _| | _____            /^/
        \___ \| '_ \ / _` | |/ / _ \          ( ( 
        ____) | | | | (_| |   |  __/          \_\_____      
       |_____/|_| |_|\__,_|_|\_\___|          (_______) 
                                             (_________()Oo
                                            
    )" << endl;


    cout << "       Witaj w grze w Snake z przeszkodami.\n       Najlepszy gracz: " << n << " z wynikiem: " << s << "\n       Elementy gry: \n       1. X - przeszkoda\n       2. F - jedzenie\n       3. O - glowa weza\n       4. #  - granica planszy\n       Podaj nazwe gracza: ";
    cin >> game.nick;
    cout << "       Aby rozpoczac gre wcisnij enter.";
    int znak = _getch();
    if (znak == 13) {
        game.run();
    }
    return 0;
}