#include "include/RecebeDados.h"
#include <iostream>

using namespace std;

int RecebeDados::pegaInt() {
	int a;
	cin >> a;
	return a;
}

string RecebeDados::pegaString() {
	string s;
	cin >> s;
	return s;
}

