#include "Rezervare.h"
#include <string.h>
#include <iostream>

Rezervare::Rezervare() {
	nume = NULL;
	cod = 0;
	loc = 0;
}
Rezervare::Rezervare(int Cod, char* Name, int Loc)
{
	this->nume = new char[strlen(Name) + 1];
	strcpy_s(this->nume, strlen(Name) + 1, Name);

	this->cod = Cod;

	this->loc = Loc;
}

Rezervare::Rezervare(const Rezervare& s) {
	this->nume = new char[strlen(s.nume) + 1];
	strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);

	this->cod = s.cod;

	this->loc = s.loc;
}

char* Rezervare::getNume() { return nume; }
int Rezervare::getCod() { return cod; }
int Rezervare::getLoc() { return loc; }


void  Rezervare::setNume(char* n)
{
	if (this->nume != NULL)
	{
		delete[]this->nume;
	}
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
}

void Rezervare::setLoc(int l)
{
	this->loc = l;
}

void Rezervare::setCod(int c)
{
	this->cod = c;
}

Rezervare& Rezervare::operator=(const Rezervare& s)
{
	if (this == &s)
		return *this; //self-assignment
	this->setNume(s.nume);
	this->setCod(s.cod);
	this->setLoc(s.loc);
	return *this;
}

bool Rezervare::operator ==(const Rezervare& s)
{
	return (strcmp(nume, s.nume) == 0) && (cod == s.cod) && (loc == s.loc);
}

Rezervare ::~Rezervare()
{
	if (nume != NULL)
		delete[]nume;
	nume = NULL;
	loc = -1;
	cod = -1;

}

ostream& operator<<(ostream& os, const Rezervare& s)
{
	os << "Zborul cu numarul: " << s.cod << " pe numele: " << s.nume << " cu locul: " << s.loc << endl;
	return os;
}

istream& operator>>(istream& is, Rezervare& s)
{
	cout << "Cod: ";
	int cod;
	cin >> cod;
	cout << "Nume: ";
	char* nume = new char[10];
	is >> nume;
	cout << "Loc: ";
	int loc;
	cin >> loc;
	s.setNume(nume);
	s.setCod(cod);
	s.setLoc(loc);
	delete[] nume;
	return is;
}
