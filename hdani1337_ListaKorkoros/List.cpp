#include "list.h"

#include <iostream>

List::List() : head(new ListItem()) {
	// Az elején csak ez az egy elem van, de mivel körkörös, magára mutat
	head->next = head->prev = head;
}

List::~List() {
	// Az utolsó elemnél a kovetkezõ értéke a head, így a korábbi megoldás nem mûködik, de szerencsére ez sem bonyolultabb
	ListItem *current = head->next;
	while (current != head) {
		current = current->next;
		delete current->prev;
	}
	delete head;
}

void List::newItem(int value) {
	// Legyen megint az elejére fûzés
	ListItem *new_item = new ListItem(value);

	// Elõször beállítjuk az új elem mutatóit a két szomszédjára
	new_item->next = head->next;
	new_item->prev = head;

	// Majd a szomszédok segítségével beláncoljuk a listába
	head->next->prev = new_item;
	head->next = new_item;

	// Fontos a sorrend. Elõbb használjuk a head->next régi értékét, csak ez után adjunk neki újat
}

void List::print() const {
	// Ismét: a head nem az elsõ elemre mutat, hanem az extra fejelemre
	ListItem *current = head->next;
	// A lista végén a kovetkezo értéke nem 0, hanem head
	while (current != head) {
		std::cout << current->value << std::endl;
		current = current->next;
	}
}

void List::printBackwards() const {
	ListItem *back = head->prev;
	while (back != head) {
		std::cout << back->value << std::endl;
		back = back->prev;
	}
}

void List::newItemBack(int value) {
	ListItem *newItem = new ListItem(value);
	newItem->next = head;
	newItem->prev = head->prev;
	newItem->prev->next = newItem;
	newItem->next->prev = newItem;
}

void List::erase(int value) {
	ListItem *current = head->next;
	while(current->next != head && current->value != value){
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
}