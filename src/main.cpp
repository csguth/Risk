/*
 ============================================================================
 Name        : Risk.cpp
 Author      : Chrystian Guth csguth@gmail.com
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include "die/die_face.h"

using namespace std;

int main(void) {
	risk::die::die_face face{1};
	cout << "Hello World" << endl; /* prints Hello World */
	return 0;
}
