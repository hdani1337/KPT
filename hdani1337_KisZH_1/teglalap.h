#pragma once
#include <iostream>

// ahol lehet (�s �rtelmes) haszn�ljon "const" kulcssz�t!
class Teglalap {
	double szelesseg, magassag;
public:
	// hozzon l�tre k�t param�ter� konstruktort, amit alap�rtelmezetten 2 sz�less�g� �s 1 magass�g� t�glalapot k�sz�t
	Teglalap(double _sz = 2, double _m = 1) {
		szelesseg = _sz;
		magassag = _m;
	}

	// hozzon l�tre * oper�tort, amely egy t�glalap m�ret�t ar�nyosan megn�veli egy eg�sz �rt�k seg�ts�g�vel
	const Teglalap operator*(unsigned int novel) const {
		Teglalap eredmeny = *this;
		eredmeny.magassag *= novel;
		eredmeny.szelesseg *= novel;
		return eredmeny;
	}
	// p�ld�ul ha a t�glalapot beszorozzuk 5-tel, akkor a sz�less�g �s a magass�got is szorozza be 5-tel

	friend std::ostream& operator<<(std::ostream &s, const Teglalap &t) {
		s << "(" << t.szelesseg << ", " << t.magassag << ")";
		return s;
	}
};