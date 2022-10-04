#pragma once
#include <iostream>

using namespace std;

class Vector
{
	unsigned int meret;
	int *tomb;
public:
	//Vector();
	Vector(const Vector&);
	~Vector();

	Vector(unsigned int _meret = 0);

	unsigned int getMeret() const { return meret; }
	int getErtek(unsigned int index) const { return tomb[index]; }

	Vector& operator=(const Vector& v);
	const Vector operator+(const Vector& v) const;
	const Vector operator*(int szam) const;
	int& operator[](unsigned int index);

	friend ostream& operator<<(ostream& stream, const Vector& v) {
		for (int i = 0; i < v.meret; i++){
			stream << v.tomb[i] << "\t";
		}
		stream << endl;
		return stream;
	};
};

const Vector operator*(int szam, const Vector &v);