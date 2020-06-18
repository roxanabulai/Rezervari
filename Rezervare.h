#pragma once
#ifndef PRODUS_H
#define PRODUS_H
#include <string>
#include<ostream>
using namespace std;
class Rezervare
{
private:
	int cod;
	char* nume;
	int loc;

public:
	Rezervare(); //constructor implicit
	Rezervare(int, char*, int); //constructor general
	Rezervare(const Rezervare&); //constructor de copiere

	int getCod();
	char* getNume();
	int getLoc();

	void setCod(int);
	void setNume(char*);
	void setLoc(int);

	Rezervare& operator=(const Rezervare&);
	bool operator==(const Rezervare&);
	~Rezervare(); //destructor

	friend ostream& operator<<(ostream& os, const Rezervare& s);
	friend istream& operator>>(istream&, Rezervare&);
};
#endif
