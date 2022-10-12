#pragma once

template <class T>
class List {
protected:
	// Oszt�lyon bel�li oszt�ly, ami k�v�lr�l nem �rhet� el. Programoz�si elv: kifel� csak az l�tsz�djon, aminek musz�j
	class ListItem {
		T value;
		ListItem *next, *prev;
		friend class List;
		ListItem(int _value = 0) : value(_value), next(nullptr), prev(nullptr) {}
	};

	// Egy kijel�lt elem kell, hogy valahol el tudjuk kezdeni
	// Kezel�s szempontj�b�l itt is mutat�
	ListItem *head;
public:

	// Ez az oszt�ly el�rhet� k�v�lr�l, hiszen az a c�lja, hogy kifel� biztos�tson interf�szt
	class Iterator {
		ListItem *item;
		friend class List; // Az �rai insert f�ggv�ny miatt kell
	public:
		Iterator(ListItem *_item = nullptr) : item(_item) {};
		// A lista elemein val� iter�l�shoz haszn�ljuk, mint ciklusv�ltoz�t, ez�rt sz�ks�g van p�r oper�torra

		bool operator == (const Iterator &other) const {
			return item == other.item;
		};

		bool operator != (const Iterator &other) const {
			return item != other.item;
		};

		Iterator operator++(T) {
			Iterator ret(item);
			item = item->next;
			return ret;
		};

		Iterator& operator++() {
			item = item->next;
			return *this;
		};

		Iterator operator--(T) {
			Iterator ret(item);
			item = item->prev;
			return ret;
		};

		Iterator& operator--() {
			item = item->prev;
			return *this;
		};
		// Referenci�val t�r�nk vissza, ami lehet�s�get ad az adat megv�ltoztat�s�ra
		T& operator *() {
			return item->value;
		};

		T& operator ->() {
			return &item->value;
		};
	};

	List() : head(new ListItem()) {
		// Az elej�n csak ez az egy elem van, de mivel k�rk�r�s, mag�ra mutat
		head->next = head->prev = head;
	};

	~List() {
		// Az utols� elemn�l a kovetkez� �rt�ke a head, �gy a kor�bbi megold�s nem m�k�dik, de szerencs�re ez sem bonyolultabb
		ListItem *current = head->next;
		while (current != head) {
			current = current->next;
			delete current->prev;
		}
		delete head;
	};

	void newItem(T value) {
		// Legyen megint az elej�re f�z�s
		ListItem *new_item = new ListItem(value);

		// El�sz�r be�ll�tjuk az �j elem mutat�it a k�t szomsz�dj�ra
		new_item->next = head->next;
		new_item->prev = head;

		// Majd a szomsz�dok seg�ts�g�vel bel�ncoljuk a list�ba
		head->next->prev = new_item;
		head->next = new_item;
		// Fontos a sorrend. El�bb haszn�ljuk a head->next r�gi �rt�k�t, cask ez ut�n adjunk neki �jat
	};
	// Itt nincs print f�ggv�ny, hiszen m�r van lehet�s�g�nk k�ls� k�db�l is el�rni az elemeket
	// Viszont kellenek f�ggv�nyek, amik lehet�v� teszik az iter�torok haszn�lat�t
	Iterator begin() {
		return Iterator(head->next);
	};

	Iterator end() {
		return Iterator(head);
	};

	// �rai feladatok
	Iterator insert(Iterator whereTo, T value) {
		ListItem *uj = new ListItem(value);
		uj->next = whereTo.item;
		uj->prev = whereTo.item->prev;

		uj->next->prev = uj;
		uj->prev->next = uj;


		return Iterator(uj);
	};


	class ReverseIterator {
		ListItem *item;
		friend class List; // Az �rai insert f�ggv�ny miatt kell
	public:
		ReverseIterator(ListItem *_item = nullptr) : item(_item) {};
		// A lista elemein val� iter�l�shoz haszn�ljuk, mint ciklusv�ltoz�t, ez�rt sz�ks�g van p�r oper�torra
		bool operator == (const ReverseIterator &other) const {
			return item == other.item;
		};

		bool operator != (const ReverseIterator &other) const {
			return item != other.item;
		};

		ReverseIterator operator++(T) {
			ReverseIterator ret(item);
			item = item->prev;
			return ret;
		};

		ReverseIterator& operator++() {
			item = item->prev;
			return *this;
		};

		ReverseIterator operator--(T) {
			ReverseIterator ret(item);
			item = item->next;
			return ret;
		};

		ReverseIterator& operator--() {
			item = item->next;
			return *this;
		};
		// Referenci�val t�r�nk vissza, ami lehet�s�get ad az adat megv�ltoztat�s�ra
		T& operator *() {
			return item->value;
		};

		T& operator ->() {
			return &item->value;
		};
	};
	ReverseIterator rbegin() {
		return ReverseIterator(head->prev);
	};
	ReverseIterator rend() {
		return ReverseIterator(head);
	};
};

