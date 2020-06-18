#pragma once
#include "RepositorySTL.h"
#include "Rezervare.h"
///#include "UtilizatorRez.h"
#include "Service.h"
#include <list>
using namespace std;
class TestService {
private:
	void testAddRezService();
	void testRemoveRezService();
	void testUpdateRezService();
	void test_functionalitate1();
	void test_functionalitate2();
	//void test_funct1();

public:
	void testAll();

};