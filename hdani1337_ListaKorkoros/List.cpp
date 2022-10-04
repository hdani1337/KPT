#include "list.h"

#include <iostream>

List::List() : head(new ListItem()) {
	// Az elej�n csak ez az egy elem van, de mivel k�rk�r�s, mag�ra mutat
	head->next = head->prev = head;
}

List::~List() {
	// Az utols� elemn�l a kovetkez� �rt�ke a head, �gy a kor�bbi megold�s nem m�k�dik, de szerencs�re ez sem bonyolultabb
	ListItem *current = head->next;
	while (current != head) {
		current = current->next;
		delete current->prev;
	}
	delete head;
}

void List::newItem(int value) {
	// Legyen megint az elej�re f�z�s
	ListItem *new_item = new ListItem(value);

	// El�sz�r be�ll�tjuk az �j elem mutat�it a k�t szomsz�dj�ra
	new_item->next = head->next;
	new_item->prev = head;

	// Majd a szomsz�dok seg�ts�g�vel bel�ncoljuk a list�ba
	head->next->prev = new_item;
	head->next = new_item;

	// Fontos a sorrend. El�bb haszn�ljuk a head->next r�gi �rt�k�t, csak ez ut�n adjunk neki �jat
}

void List::print() const {
	// Ism�t: a head nem az els� elemre mutat, hanem az extra fejelemre
	ListItem *current = head->next;
	// A lista v�g�n a kovetkezo �rt�ke nem 0, hanem head
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