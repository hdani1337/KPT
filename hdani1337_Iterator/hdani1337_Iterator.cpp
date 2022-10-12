#include <iostream>
#include "list.h"

int main() {
    List<int> my_list; // Egy Lista t�pus� v�ltoz�
    // Adjuk hozz� a h�rom elemet
    my_list.newItem(5);
    my_list.newItem(3);
    my_list.newItem(2);
    // Majd list�zzuk ki
    std::cout << "List" << std::endl;
    List<int>::Iterator list_it;
    for (list_it = my_list.begin(); list_it != my_list.end(); list_it++)
        std::cout << *list_it << std::endl;
    std::cout << std::endl;
    std::cout << "RevList" << std::endl;
    List<int>::ReverseIterator rev_list_it = my_list.rbegin();
    for (; rev_list_it != my_list.rend(); ++rev_list_it)
        std::cout << *rev_list_it << std::endl;
    std::cout << std::endl;

    // Az elemek n�vekv� sorrendben vannak, ennek megfelel�en sz�rjuk be a 4-et
    List<int>::Iterator list_it2;
    for(list_it2 = my_list.begin(); list_it2 != my_list.end() && *list_it2 < 4; ++list_it2)
        ;
    my_list.insert(list_it2, 4);
    // Majd a 7-et is
    for(list_it2 = my_list.begin(); list_it2 != my_list.end() && *list_it2 < 7; ++list_it2)
        ;
    my_list.insert(list_it2, 7);

    std::cout << "List" << std::endl;
    for(list_it = my_list.begin(); list_it != my_list.end(); ++list_it)
        std::cout << *list_it << std::endl;
    std::cout << std::endl;

    return 0;
}