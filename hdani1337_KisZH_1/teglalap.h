#pragma once
#include <iostream>

// ahol lehet (és értelmes) használjon "const" kulcsszót!
class Teglalap {
	double szelesseg, magassag;
public:
	// hozzon létre két paraméterû konstruktort, amit alapértelmezetten 2 szélességû és 1 magasságú téglalapot készít
	Teglalap(double _sz = 2, double _m = 1) {
		szelesseg = _sz;
		magassag = _m;
	}

	// hozzon létre * operátort, amely egy téglalap méretét arányosan megnöveli egy egész érték segítségével
	const Teglalap operator*(unsigned int novel) const {
		Teglalap eredmeny = *this;
		eredmeny.magassag *= novel;
		eredmeny.szelesseg *= novel;
		return eredmeny;
	}
	// például ha a téglalapot beszorozzuk 5-tel, akkor a szélesség és a magasságot is szorozza be 5-tel

	friend std::ostream& operator<<(std::ostream &s, const Teglalap &t) {
		s << "(" << t.szelesseg << ", " << t.magassag << ")";
		return s;
	}
};