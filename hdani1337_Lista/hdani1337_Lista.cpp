#include <iostream>
#include "list.h"

int main()
{
	List my_list; // Egy Lista t�pus� v�ltoz�
	// Adjuk hozz� a h�rom elemet
	my_list.newItem(5);
	my_list.newItem(3);
	my_list.newItem(2);

	// Majd list�zzuk ki
	std::cout << "List" << std::endl;
	my_list.print();
	std::cout << std::endl;

	// T�r�lj�nk elemeket
	my_list.erase(1);
	my_list.erase(2);
	std::cout << "List" << std::endl;
	my_list.print();
	std::cout << std::endl;

	// Adjunk elemeket a v�g�re
	my_list.newItemBack(1);
	my_list.newItemBack(7);
	std::cout << "List" << std::endl;
	my_list.print();
	std::cout << std::endl;
	return 0;
}
