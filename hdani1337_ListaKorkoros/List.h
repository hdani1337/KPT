#pragma once

class List {
protected:
	// Osztályon belüli osztály, ami kívülrõl nem érhetõ el. Programozási elv: kifelé csak az látszódjon, aminek muszáj
	class ListItem {
		int value;
		ListItem *next, *prev;
		friend class List;
		ListItem(int _value = 0) : value(_value), next(nullptr), prev(nullptr) {}
	};

	// Egy kijelölt elem kell, hogy valahol el tudjuk kezdeni
	// Kezelés szempontjából itt is mutató
	ListItem *head;
public:
	List();
	~List();
	void newItem(int value);
	void print() const;

	// Órai feladatok
	void printBackwards() const;
	void newItemBack(int value);
	void erase(int value);
};