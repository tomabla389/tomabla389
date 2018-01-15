#include <iostream>
#include <string>
using namespace std;


struct str {
	string imie = " ";
	string nazwisko = " ";
	int tab[10] = { 0 };
};

struct element {
	str *student;
	element*next;
	element*prev;
};

struct lista {
	element *poczatek;
	element *koniec;
	int dlg;
	bool dodaj(str*nowystudent, int pozycja)
	{
		if (pozycja<0 || pozycja>dlg)
			return 1;
		element*current = poczatek;
		element*nowyelement = new element;
		if (pozycja == 0)
		{
			if (poczatek != nullptr) poczatek->prev = nowyelement;
			nowyelement->next = poczatek;
			poczatek = nowyelement;
			nowyelement->prev = nullptr;
		}
		else {
			element*current = poczatek;
			for (int i = 1;i < pozycja;i++)
			{
				current = current->next;
			}
			nowyelement->next = current->next;
			nowyelement->prev = current;
			current->next = nowyelement;
			if (current->next != nullptr) current->next->prev = nowyelement;
		}
		if (pozycja == dlg) koniec = nowyelement;
		dlg++;
	}
};
