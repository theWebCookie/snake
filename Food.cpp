#include "Food.h"
#include <iostream>

using namespace std;

void Food::info(int n) {
	Object::info(n);
	cout << "Stworzono " << n << " jedzen" << (n == 1 ? "ie" : (n > 1 && n < 5 ? "ia" : "")) << endl;
}