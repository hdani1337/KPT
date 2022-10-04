#include "pch.h"
#include <iostream>
#include "list.h"
#include "komplex.h"

int main() {

	std::cout << "Egész szamok a listába" << std::endl;
	List<int> l;
	for (unsigned int i = 0; i < 10; i++)
		l.push_back(i);
	std::cout << l << std::endl;
	for (unsigned int i = 0; i < 10; i++)
		l.push_front(i);
	std::cout << l << std::endl;


	std::cout << "Komplex szamok a listába" << std::endl;
	List<komplex> l3;
	for (unsigned int i = 0; i < 7; i++)
		l3.push_back(komplex(i, i));
	std::cout << l3 << std::endl;
	for (unsigned int i = 0; i < 7; i++)
		l3.push_front(komplex(i, i));
	std::cout << l3 << std::endl;


	std::cout << std::endl << "Kivetelkezeles" << std::endl;
	List<int> l2;

	// Kivételkezelés
	try {
		std::cout << "l2.push_back(3) ";
		l2.push_back(3);
		std::cout << "OK" << std::endl;

		std::cout << "l2.pop_front() ";
		l2.pop_front();
		std::cout << "OK" << std::endl;

		std::cout << "l2.pop_back() ";
		l2.pop_back();
		std::cout << "OK" << std::endl;

		std::cout << "l2.push_back(5) ";
		l2.push_back(5);
		std::cout << "OK" << std::endl;

		std::cout << "l2.push_front(2) ";
		l2.push_front(2);
		std::cout << "OK" << std::endl;

		std::cout << "l2.pop_back() ";
		l2.pop_back();
		std::cout << "OK" << std::endl;

		std::cout << l2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// Kivételkezelés vége
}