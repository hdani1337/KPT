#pragma once

class List {
protected:
	// Oszt�lyon bel�li oszt�ly, ami k�v�lr�l nem �rhet� el. Programoz�si elv: kifel� csak az l�tsz�djon, aminek musz�j
	class ListItem {
		int value;
		ListItem *next, *prev;
		friend class List;
		ListItem(int _value = 0) : value(_value), next(nullptr), prev(nullptr) {}
	};

	// Egy kijel�lt elem kell, hogy valahol el tudjuk kezdeni
	// Kezel�s szempontj�b�l itt is mutat�
	ListItem *head;
public:
	List();
	~List();
	void newItem(int value);
	void print() const;

	// �rai feladatok
	void printBackwards() const;
	void newItemBack(int value);
	void erase(int value);
};