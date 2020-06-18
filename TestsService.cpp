#include "TestsService.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
void TestService::testAddRezService()
{
	RepositorySTL<Rezervare> repo;
	Service serv;
	serv.setRepo(repo);
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
	serv.addRezervare(r1);
	serv.addRezervare(r2);
	assert(serv.getAll().size() == 2);
}
void TestService::testRemoveRezService()
{
	RepositorySTL<Rezervare> repo;
	Service serv;
	serv.setRepo(repo);
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
	serv.addRezervare(r1);
	serv.addRezervare(r2);
	serv.delRezervare(r1);
	assert(serv.getAll().size() == 1);
}
void TestService::testUpdateRezService()
{
	RepositorySTL<Rezervare> repo;
	Service serv;
	serv.setRepo(repo);
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
	serv.addRezervare(r1);
	serv.addRezervare(r2);
	int cod_nou;
	cod_nou = 1000;
	char* nume_nou = new char[10];
	strcpy_s(nume_nou, sizeof "Alina", "Alina");
	int loc_nou;
	loc_nou = 10;
	serv.updateRezervare(r1, cod_nou, nume_nou, loc_nou);
	Rezervare r_new(cod_nou, nume_nou, loc_nou);
	assert(serv.findOne(r_new) != 1);

}
void TestService::test_functionalitate1()
{
	RepositorySTL<Rezervare> repo;
	list<Rezervare> rezervari;
	Service serv;
	serv.setRepo(repo);
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
	loc2 = 55;
	Rezervare r1(cod1, nume1, loc1);
	Rezervare r2(cod2, nume2, loc2);
	assert(serv.functionalitate1(rezervari, r1, 50) == 2);
	assert(serv.functionalitate1(rezervari, r2, 50) == -1);
}
void TestService::test_functionalitate2()
{
	RepositorySTL<Rezervare> repo;
	Service serv;
	serv.setRepo(repo);
	list<Rezervare> rezervari;
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
	loc2 = 55;
	Rezervare r1(cod1, nume1, loc1);
	Rezervare r2(cod2, nume2, loc2);
	assert(serv.functionalitate1(rezervari, r1, 50) == 2);
	assert(serv.functionalitate1(rezervari, r2, 50) == -1);
	serv.addRezervare(r1);
	int cod3;
	int loc3;
	cod3 = 1221;
	loc3 = 10;
	char* nume3 = new char[10];
	strcpy_s(nume3, sizeof "Alex", "Alex");
	Rezervare r3(cod3, nume3, loc3);
	assert(serv.functionalitate2(rezervari, r3, 50) == 0);


}

void TestService::testAll()
{
	testAddRezService();
	testRemoveRezService();
	testUpdateRezService();
	test_functionalitate1();
	test_functionalitate2();

}