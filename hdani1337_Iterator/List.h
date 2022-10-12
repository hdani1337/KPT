#pragma once

template <class T>
class List {
protected:
	// Osztályon belüli osztály, ami kívülrõl nem érhetõ el. Programozási elv: kifelé csak az látszódjon, aminek muszáj
	class ListItem {
		T value;
		ListItem *next, *prev;
		friend class List;
		ListItem(int _value = 0) : value(_value), next(nullptr), prev(nullptr) {}
	};

	// Egy kijelölt elem kell, hogy valahol el tudjuk kezdeni
	// Kezelés szempontjából itt is mutató
	ListItem *head;
public:

	// Ez az osztály elérhetõ kívülrõl, hiszen az a célja, hogy kifelé biztosítson interfészt
	class Iterator {
		ListItem *item;
		friend class List; // Az órai insert függvény miatt kell
	public:
		Iterator(ListItem *_item = nullptr) : item(_item) {};
		// A lista elemein való iteráláshoz használjuk, mint ciklusváltozót, ezért szükség van pár operátorra

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
		// Referenciával térünk vissza, ami lehetõséget ad az adat megváltoztatására
		T& operator *() {
			return item->value;
		};

		T& operator ->() {
			return &item->value;
		};
	};

	List() : head(new ListItem()) {
		// Az elején csak ez az egy elem van, de mivel körkörös, magára mutat
		head->next = head->prev = head;
	};

	~List() {
		// Az utolsó elemnél a kovetkezõ értéke a head, így a korábbi megoldás nem mûködik, de szerencsére ez sem bonyolultabb
		ListItem *current = head->next;
		while (current != head) {
			current = current->next;
			delete current->prev;
		}
		delete head;
	};

	void newItem(T value) {
		// Legyen megint az elejére fûzés
		ListItem *new_item = new ListItem(value);

		// Elõször beállítjuk az új elem mutatóit a két szomszédjára
		new_item->next = head->next;
		new_item->prev = head;

		// Majd a szomszédok segítségével beláncoljuk a listába
		head->next->prev = new_item;
		head->next = new_item;
		// Fontos a sorrend. Elõbb használjuk a head->next régi értékét, cask ez után adjunk neki újat
	};
	// Itt nincs print függvény, hiszen már van lehetõségünk külsõ kódból is elérni az elemeket
	// Viszont kellenek függvények, amik lehetõvé teszik az iterátorok használatát
	Iterator begin() {
		return Iterator(head->next);
	};

	Iterator end() {
		return Iterator(head);
	};

	// Órai feladatok
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
		friend class List; // Az órai insert függvény miatt kell
	public:
		ReverseIterator(ListItem *_item = nullptr) : item(_item) {};
		// A lista elemein való iteráláshoz használjuk, mint ciklusváltozót, ezért szükség van pár operátorra
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
		// Referenciával térünk vissza, ami lehetõséget ad az adat megváltoztatására
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

