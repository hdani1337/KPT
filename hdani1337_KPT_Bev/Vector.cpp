#include "Vector.h"

/*Vector::Vector()
{
	meret = 0;
	tomb = nullptr;
}*/

Vector::~Vector()
{
	delete tomb;
}

Vector::Vector(const Vector &v) {
	meret = v.meret;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++) {
		tomb[i] = v.tomb[i];
	}
}

Vector::Vector(unsigned int _meret) {
	meret = _meret;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++) {
		tomb[i] = i;
	}
}

Vector& Vector::operator=(const Vector& v) {
	meret = v.meret;
	delete tomb;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++) {
		tomb[i] = v.tomb[i];
	}
	return *this;
}

int& Vector::operator[](unsigned int index) {
	return tomb[index];
}

const Vector Vector::operator+(const Vector& v) const {
	Vector sum;
	sum.meret = (meret > v.getMeret()) ? meret : v.getMeret();
	sum.tomb = new int[sum.meret];

	for (int i = 0; i < sum.getMeret(); i++) sum.tomb[i] = 0;//összeg tömb nullázása
	for (int i = 0; i < getMeret(); i++) sum.tomb[i] += tomb[i];//feltöltés az egyik tömbbel
	for (int i = 0; i < v.getMeret(); i++) sum.tomb[i] += v.tomb[i];//másik tömb hozzáadása
	
	return sum;
}

const Vector Vector::operator*(int szam) const {
	Vector sum(*this);

	for (int i = 0; i < sum.getMeret(); i++) sum.tomb[i] *= szam;

	return sum;
}

const Vector operator*(int szam, const Vector &v) {
	return v * szam;
}