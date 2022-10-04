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
	std::cout << "ListBack" << std::endl;
	my_list.printBackwards();
	std::cout << std::endl;
	my_list.newItemBack(8);
	my_list.newItemBack(9);
	std::cout << "List" << std::endl;
	my_list.print();
	my_list.erase(2);
	std::cout << std::endl;
	std::cout << "ListBack" << std::endl;
	my_list.printBackwards();
	std::cout << std::endl;
	return 0;
}
