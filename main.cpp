#include "Rezervare.h"
#include "TestsRezervare.h"
#include "TestsRepositorySTL.h"
#include "TestsService.h"
#include "Service.h"
#include "UI.h"
#include "RepoFile.h"
#include <iostream>
using namespace std;


int main()
{
	testConstructors();
	//Teste REPO
	TestRepoAdd();
	TestRepoUpdate();
	TestRepoRemove();

	//Teste Service
	TestService testservice;
	testservice.testAll();
	// UI
	Service serv;
	UI ui;
	ui.showUI();
	cout << "succes";

	return 0;
}
