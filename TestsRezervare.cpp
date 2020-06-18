#include<iostream>
#include "Rezervare.h"
#include "TestsRezervare.h"
#include <assert.h>


void testConstructors() {
	//static
	Rezervare r;//implicit const
	assert((r.getCod() == 0) && (r.getNume() == NULL) && (r.getLoc() == 0));

	int cod1;
	cod1 = 1112;
	char* nume1 = new char[10];
	strcpy_s(nume1, sizeof "Rox", "Rox");
	int loc1;
	loc1 = 13;
	Rezervare r1(cod1, nume1, loc1);//const with param

	assert((r1.getCod() == 1112) && (strcmp(r1.getNume(), "Rox") == 0) && (r1.getLoc() == 13));

	//dynamic
	Rezervare* r2;
	r2 = new Rezervare();//implicit constr
	assert((r2->getCod() == 0) && (r2->getNume() == NULL) && (r2->getLoc() == 0));

	int cod2;
	cod2 = 1113;
	char* nume2 = new char[10];
	strcpy_s(nume2, sizeof "Ioana", "Ioana");
	int loc2;
	loc2 = 15;
	Rezervare* r3 = new Rezervare(cod2, nume2, loc2);//const by param
	assert((r3->getCod() == 1113) && (strcmp(r3->getNume(), "Ioana") == 0) && (r3->getLoc() == 15));
	if (r3 != NULL) {
		delete r3;//destructor
		r3 = NULL;
	}

}