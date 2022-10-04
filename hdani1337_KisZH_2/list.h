#pragma once
#include <string>
#include <iostream>
#include "UresListaException.h"

template 
<class Tipus>
class List {
protected:
	class ListItem {
		Tipus value;
		ListItem *next;
		friend class List;
		ListItem(Tipus _value) : value(_value), next(nullptr) {}
	public:
		Tipus getValue() const { return value; }
		ListItem* getNext() const { return next; }
	};

	ListItem *head;

public:
	List() {
		head = nullptr;
	}

	~List() {
		ListItem *current;
		while(head != nullptr) {
			current = head->next;
			delete head;
			head = current;
		}
	}

	void push_front(Tipus value) {
		ListItem *newItem = new ListItem(value);
		newItem->next = head;
		head = newItem;
	}

	void push_back(Tipus value) {
		ListItem *newItem = new ListItem(value);
		ListItem *current = head;
		if(head == nullptr)
			head = newItem;
		else {
			while(current->next != nullptr)
				current = current->next;
			current->next = newItem;
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	// Kivételkezelés
	void pop_front() {
		try {
			ListItem *toDelete = head;
			head = head->next;
			if(toDelete != nullptr)
				delete toDelete;
			else throw new UresListaException("Üres a lista!");
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

	}

	// Kivételkezelés
	void pop_back() {
		
			ListItem *toDelete = head;
			ListItem *prev = nullptr;
		try {
			if (toDelete != nullptr) {
				while (toDelete->next != nullptr) {
					prev = toDelete;
					toDelete = toDelete->next;
				}
				if (prev != nullptr)
					prev->next = nullptr;
				else
					head = nullptr;
				delete toDelete;
			}

		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	friend std::ostream& operator <<(std::ostream &s, const List &l) {
		List::ListItem *current = l.head;
		while(current != nullptr) {
			s << current->getValue() << " ";
			current = current->getNext();
		}
		return s;
	}
};