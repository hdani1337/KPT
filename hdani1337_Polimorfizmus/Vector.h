#pragma once
#include <iostream>

template <class Tipus>
class Vector
{
	unsigned int meret;
	Tipus *tomb;
public:
	Vector(const Vector& v) {
		meret = v.meret;
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++) {
			tomb[i] = v.tomb[i];
		}
	};

	~Vector() {
		delete [] tomb;
	};

	Vector(unsigned Tipus _meret = 0) : meret(_meret) {
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++) {
			tomb[i] = i;
		}
	};

	unsigned int getMeret() const { return meret; }
	Tipus getErtek(unsigned int index) const { return tomb[index]; }

	Vector& operator=(const Vector& v) {
		meret = v.meret;
		delete [] tomb;
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++) {
			tomb[i] = v.tomb[i];
		}
		return *this;
	};

	const Vector operator+(const Vector& v) const {
		Vector sum;
		sum.meret = (meret > v.getMeret()) ? meret : v.getMeret();
		sum.tomb = new Tipus[sum.meret];

		for (int i = 0; i < sum.getMeret(); i++) sum.tomb[i] = 0;//összeg tömb nullázása
		for (int i = 0; i < getMeret(); i++) sum.tomb[i] += tomb[i];//feltöltés az egyik tömbbel
		for (int i = 0; i < v.getMeret(); i++) sum.tomb[i] += v.tomb[i];//másik tömb hozzáadása

		return sum;
	};

	const Vector operator*(int szam) const {
		Vector sum(*this);

		for (int i = 0; i < sum.getMeret(); i++) sum.tomb[i] *= szam;

		return sum;
	};

	Tipus& operator[](unsigned int index) {
		if(index < meret && index >= 0)
			return tomb[index];
		else throw std::string("Túlcímzés");
	};

	friend ostream& operator<<(ostream& stream, const Vector& v) {
		for (int i = 0; i < v.meret; i++){
			stream << v.tomb[i] << "\t";
		}
		stream << endl;
		return stream;
	};
};

template class<Tipus>
const Vector operator*(int szam, const Vector &v) {
	return v * szam;
};