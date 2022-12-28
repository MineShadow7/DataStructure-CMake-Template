// Copyright 2022 Andrey Karagodin

#include <stdio.h>
#include <string>
#include "../lib_polish/polish.h"
#include "main.h"

void main() {
	string expl;
	int x = 1;
	cout << "Available symbols: 'x', '+', '-', '*', '/', '(', ')'." << endl;
	cout << "Input your formula (without spaces): ";
	cin >> expl;
	cout << endl;
	cout << "Input x: ";
	cin >> x;
	Calculator cal;
	float result;
	result = cal.calculate(expl, 25);
	cout << endl;
	cout << "The result is: " << result;
}
