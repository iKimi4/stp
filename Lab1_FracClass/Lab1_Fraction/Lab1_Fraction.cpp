#include "pch.h"
#include <iostream>

int main() {
	string str = "1/2";
	TFrac a(str);
	std::cout << a.getFractionString() << endl;
	//a = a.add(b);
    std:cout << a.getFractionString() << endl;
}