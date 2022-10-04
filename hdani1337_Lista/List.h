#ifndef LIST_H
#define LIST_H

class List {
protected:
	// Osztályon belüli osztály, ami kívülrõl nem érhetõ el. Programozási elv: kifelé csak az látszódjon, aminek muszáj
	class ListItem {
		// Nem publikus adattagok
		int value;
		ListItem *next;
		friend class List; // Viszont a List osztály számára legyenek elérhetõek
		ListItem(int _value) : value(_value), next(nullptr) {}
	};

	ListItem *head;
public:
	List();
	~List();
	void newItem(int value);
	void print() const;

	// Órai feladatok
	void erase(int value);
	void newItemBack(int value);
};

#endif // LIST_H