#include "RepositorySTL.h"
#include "Rezervare.h"
#include "TestsRepositorySTL.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <list>

void TestRepoAdd()
{
	RepositorySTL<Rezervare> elem;

	char* nume1 = new char[10];
	char* nume2 = new char[10];
	int cod1;
	int cod2;
	int loc1;
	int loc2;
	strcpy_s(nume1, sizeof "Alex", "Alex");
	strcpy_s(nume2, sizeof "Ana", "Ana");
	cod1 = 1221;
	cod2 = 1111;
	loc1 = 10;
	loc2 = 15;
	Rezervare r1(cod1, nume1, loc1);
	Rezervare r2(cod2, nume2, loc2);
	elem.addItem(r1);
	elem.addItem(r2);
	assert(int(elem.getAll().size()) == 2);

}
void TestRepoRemove()
{
	RepositorySTL<Rezervare> elem;

	char* nume1 = new char[10];
	char* nume2 = new char[10];
	int cod1;
	int cod2;
	int loc1;
	int loc2;
	strcpy_s(nume1, sizeof "Alex", "Alex");
	strcpy_s(nume2, sizeof "Ana", "Ana");
	cod1 = 1221;
	cod2 = 1111;
	loc1 = 10;
	loc2 = 15;
	Rezervare r1(cod1, nume1, loc1);
	Rezervare r2(cod2, nume2, loc2);
	elem.addItem(r1);
	elem.addItem(r2);
	elem.delElem(r1);
	assert(int(elem.getAll().size()) == 1);
}

void TestRepoUpdate()
{
	RepositorySTL<Rezervare> elem;

	char* nume1 = new char[10];
	char* nume2 = new char[10];
	int cod1;
	int cod2;
	int loc1;
	int loc2;
	strcpy_s(nume1, sizeof "Alex", "Alex");
	strcpy_s(nume2, sizeof "Ana", "Ana");
	cod1 = 1221;
	cod2 = 1111;
	loc1 = 10;
	loc2 = 15;
	Rezervare r1(cod1, nume1, loc1);
	Rezervare r2(cod2, nume2, loc2);
	elem.addItem(r1);
	elem.addItem(r2);
	int cod_nou;
	cod_nou = 1000;
	char* nume_nou = new char[10];
	strcpy_s(nume_nou, sizeof "Alina", "Alina");
	int loc_nou;
	loc_nou = 10;
	elem.updateElem(r1, cod_nou, nume_nou, loc_nou);
	assert(elem.getAll().front().getCod() == 1000);
	assert(elem.getAll().front().getLoc() == 10);
	assert(strcmp(elem.getAll().front().getNume(), "Alina") == 0);
}