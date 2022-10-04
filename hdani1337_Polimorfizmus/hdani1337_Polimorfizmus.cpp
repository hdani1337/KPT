#include <iostream>

#include "Vector.h"

using namespace std;

int main() {
	Vector v(10);
	Vector v2 = v;
	Vector osszeg = v + v2;
	Vector osszegOtszor = osszeg * 5;

	cout << "v:\t\t" << v;
	cout << "v2:\t\t" << v2;
	cout << "v+v2:\t\t" << osszeg;
	cout << "(v+v2)*5:\t" << osszegOtszor;

	system("pause");
}