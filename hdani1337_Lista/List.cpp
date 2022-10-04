#include "list.h"

#include <iostream>

List::List() : head(0) {
}

List::~List() {
	ListItem *current = head;
	while (head != nullptr) {
		current = head;
		head = head->next;
		delete current;
	}
}

void List::newItem(int value) {
	ListItem *new_item = new ListItem(value);
	new_item->next = head; // Igen, a List osztály eléri a ListItem adattagjait, emlékezzünk a friend-re
	head = new_item;
}

void List::print() const {
	ListItem *current = head;
	while (current != nullptr) {
		std::cout << current->value << std::endl;
		current = current->next;
	}
}

void List::erase(int value)
{
	ListItem *current = head;
	ListItem *prev = nullptr;
	while (current->next != nullptr && current->value != value) {
		prev = current;
		current = current->next;
	}
	if (current != nullptr) {
		if (prev == nullptr) head = current->next;
		else prev->next = current->next;
		delete current;
	}
}

void List::newItemBack(int value)
{
	ListItem *current = head;
	ListItem *newItem = new ListItem(value);
	if (head == nullptr) {
		head = newItem;
		return;
	}
	while (current->next != nullptr) 
		current = current->next;
	current->next = newItem;
}