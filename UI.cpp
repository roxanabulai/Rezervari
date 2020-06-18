
#include "Service.h"
#include "UI.h"
#include <iostream>
#include <Windows.h>
//#include "UtilizatorRez.h"
using namespace std;

UI::UI()
{
}

UI::UI(Service& s)
{
	serv = s;
}

void UI::addUtilizatorRez_UI(int loc_disp)
{
	int cod;
	cout << "Dati numarul zborului: ";
	cin >> cod;
	char* nume = new char[10];
	cout << "Dati numele:";
	cin >> nume;
	int loc;
	cout << "Dati numarul locului dorit:";
	cin >> loc;
	Rezervare r(cod, nume, loc);
	list<Rezervare> rezervari = serv.getAll();
	//prima rezervare
	if (serv.functionalitate1(rezervari, r, loc_disp) == 2)
	{
		serv.addRezervare(r);
		cout << endl;
		cout << "Rezervarea a fost realizata cu succces! ";
	}
	//loc disp
	if (serv.functionalitate1(rezervari, r, loc_disp) == 1)
	{
		serv.addRezervare(r);
		cout << endl;
		cout << "Rezervarea a fost realizata cu succces! ";
	}
	//locul dorit nu e disp
	if (serv.functionalitate1(rezervari, r, loc_disp) == 0)
	{
		cout << endl;
		cout << "Locul dorit nu este disponibil!" << endl;
		cout << "Puteti alege un loc liber din lista: ";

		list<Rezervare> rezervari = serv.getAll();
		int i = 1;
		while (i <= loc_disp)
		{
			int ok = 1;//pp ca locul nu e rezv
			for (Rezervare rezv : rezervari)
			{
				if (rezv.getCod() == r.getCod())
				{
					if (rezv.getLoc() == i) {
						ok = 0; break;
					}
				}
			}
			if (ok == 1) cout << i << ",";
			i++;
		}
		char optiune[10];
		cout << endl;
		cout << "	Introduceti DA daca vreti sa rezervati un loc disponibil! ";
		cout << endl;
		cout << "	Introduceti NU daca vreti sa renuntati! ";
		cout << endl;
		cin >> optiune;
		if (strcmp(optiune, "DA") == 0)
		{
			cout << "Scrieti locul dorit(disponibil): ";
			int loc_nou;
			cin >> loc_nou;
			Rezervare r_nou(cod, nume, loc_nou);
			serv.addRezervare(r_nou);
			cout << endl;
			cout << "Rezervarea a fost adaugata cu succes! ";
		}
		else cout << "STOP";
	}
	//locul dorit nu exista
	if (serv.functionalitate1(rezervari, r, loc_disp) == -1)
	{
		cout << endl;
		cout << "Locul ales nu exista! " << endl;
		cout << "Puteti alege un loc liber din lista: ";
		int i = 1;
		list<Rezervare> rezervari = serv.getAll();
		while (i <= loc_disp)
		{
			int ok = 1;
			for (Rezervare rezv : rezervari)
			{
				if (rezv.getCod() == r.getCod())
				{
					if (rezv.getLoc() == i) ok = 0;
				}
			}
			if (ok == 1) cout << i << ",";
			i++;
		}

		char optiune[10];
		cout << endl;
		cout << "	Introduceti DA daca vreti sa rezervati un loc disponibil! ";
		cout << endl;
		cout << "	Introduceti NU daca vreti sa renuntati! ";
		cout << endl;
		cin >> optiune;
		if (strcmp(optiune, "DA") == 0)
		{
			cout << "Scrieti locul dorit(disponibil): ";
			int loc_nou;
			cin >> loc_nou;
			Rezervare r_nou(cod, nume, loc_nou);
			serv.addRezervare(r_nou);
			cout << endl;
			cout << "Rezervarea a fost adaugata cu succes! ";
		}
		else cout << "STOP";
	}

}
void UI::modificareRez_UI(int loc_disp)
{
	int cod;
	cout << "Dati numarul zborului: ";
	cin >> cod;
	char* nume = new char[10];
	cout << "Dati numele: ";
	cin >> nume;
	int loc;
	cout << "Dati numarul locului dorit: ";
	cin >> loc;
	Rezervare r(cod, nume, loc);
	list<Rezervare> rezervari = serv.getAll();
	if (serv.functionalitate2(rezervari, r, loc_disp) == 0) {
		cout << endl; cout << "Nu exista rezervarea data! ";
	}
	else {
		cout << endl;
		cout << "Rezervarea a fost gasita!";
		cout << endl;
		cout << "Introduceti numarul noului loc: ";
		int loc_nou;
		cin >> loc_nou;
		Rezervare r_nou(cod, nume, loc_nou);
		cout << endl;
		if (serv.functionalitate1(rezervari, r_nou, loc_disp) == 1)
		{
			serv.delRezervare(r);
			serv.addRezervare(r_nou);
			cout << "Rezervarea a fost modificata";
		}
		if (serv.functionalitate1(rezervari, r_nou, loc_disp) == 0) cout << "Locul introdus nu este disponibil";
		if (serv.functionalitate1(rezervari, r_nou, loc_disp) == -1) cout << "Locul introdus nu exista";

	}
}
void UI::findRezervare_UI() {
	int cod;
	cout << "Dati numarul zborului: ";
	cin >> cod;
	char* nume = new char[10];
	cout << "Dati numele:";
	cin >> nume;
	int loc;
	cout << "Dati numarul locului:";
	cin >> loc;
	Rezervare r(cod, nume, loc);
	int rez = serv.findOne(r);
	if (rez != -1) cout << "Rezervarea a fost gasita!" << endl;
	else cout << "Rezervarea NU a fost gasita!" << endl;
	delete[]nume;
}

void UI::deleteRezervare_UI() {
	int cod;
	cout << "Dati numarul zborului: ";
	cin >> cod;
	char* nume = new char[10];
	cout << "Dati numele:";
	cin >> nume;
	int loc;
	cout << "Dati numarul locului:";
	cin >> loc;
	Rezervare r(cod, nume, loc);
	int rez = serv.delRezervare(r);
	if (rez == 0) cout << "Rezervarea a fost  stearsa cu succes!" << endl;
	else cout << "Rezervarea NU a fost stearsa pentru ca NU EXISTA!" << endl;
}

void UI::updateRezervare_UI()
{
	int cod;
	cout << "Dati numarul zborului: ";
	cin >> cod;
	char* nume = new char[10];
	cout << "Dati numele:";
	cin >> nume;
	int loc;
	cout << "Dati numarul locului:";
	cin >> loc;
	Rezervare r(cod, nume, loc);
	int rez = serv.findOne(r);
	if (rez != -1) {
		int cod_nou;
		cout << endl;
		cout << "Dati numarul zborului actualizat: ";
		cin >> cod_nou;
		char* nume_nou = new char[10];
		cout << "Dati numele actualizat:";
		cin >> nume_nou;
		int loc_nou;
		cout << "Dati numarul locului actualizat:";
		cin >> loc_nou;

		serv.updateRezervare(r, cod_nou, nume_nou, loc_nou);
		cout << "Rezervarea a fost actualizata cu succes!";
	}
	else cout << "Rezervarea NU a fost actualizata pentru ca NU EXISTA!" << endl;
}

void UI::showAll_UI() {
	cout << "!!! TOATE REZERVARILE !!!" << endl;
	cout << endl;
	list<Rezervare> zboruri = serv.getAll();
	for (Rezervare r : zboruri)
		cout << r;
	cout << endl;
	cout << "        | ----------------------------|" << endl;
}

void UI::showUI()
{
	int loc_disp = 50;
	int locuri[50];
	cout << "Locuri disponibile: " << loc_disp;
	for (int i = 1; i <= loc_disp; i++)
		locuri[i] = 1;//1=DISPONIBIL
	bool gata = false;
	while (!gata) {
		//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga rezervare(daca sunt locuri disponibile) " << endl;
		cout << "	2. Cauta rezervare " << endl;
		cout << "	3. Sterge rezervare " << endl;
		cout << "	4. Afiseaza toate rezervarile " << endl;
		cout << "	5. Actualizare rezervare " << endl;
		cout << "	6. Modificare rezervare " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		//SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		switch (opt) {
		case 1: {addUtilizatorRez_UI(loc_disp); break; }
		case 2: {findRezervare_UI(); break; }
		case 3: {deleteRezervare_UI(); break; }
		case 4: {showAll_UI(); break; }
		case 5: {updateRezervare_UI(); break; }
		case 6: {modificareRez_UI(loc_disp); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		default: {cout << "OPTIUNEA NU EXISTA! VA RUGAM SELECTATI UNA DIN OPTIUNILE EXISTENTE:" << endl; }
		}
	}
}

UI::~UI()
{
}

