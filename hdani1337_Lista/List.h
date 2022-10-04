#ifndef LIST_H
#define LIST_H

class List {
protected:
	// Oszt�lyon bel�li oszt�ly, ami k�v�lr�l nem �rhet� el. Programoz�si elv: kifel� csak az l�tsz�djon, aminek musz�j
	class ListItem {
		// Nem publikus adattagok
		int value;
		ListItem *next;
		friend class List; // Viszont a List oszt�ly sz�m�ra legyenek el�rhet�ek
		ListItem(int _value) : value(_value), next(nullptr) {}
	};

	ListItem *head;
public:
	List();
	~List();
	void newItem(int value);
	void print() const;

	// �rai feladatok
	void erase(int value);
	void newItemBack(int value);
};

#endif // LIST_H