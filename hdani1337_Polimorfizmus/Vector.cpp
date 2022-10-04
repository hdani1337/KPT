#include "Vector.h"
/*Vector::Vector()
{
	meret = 0;
	tomb = nullptr;
}*/


int& Vector::operator[](unsigned int index) {
	return tomb[index];
}