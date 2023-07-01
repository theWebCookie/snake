#include "Obstacle.h"
#include <iostream>

using namespace std;

void Obstacle::info(int n) {
	cout << "Stworzono " << n << " przeszkod" << (n == 1 ? "e" : (n > 1 && n < 5 ? "y" : "")) << endl;
}