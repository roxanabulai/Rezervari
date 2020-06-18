#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
	//void addRezervare_UI(loc_disp);
	void addUtilizatorRez_UI(int);
	void findRezervare_UI();
	void deleteRezervare_UI();
	void updateRezervare_UI();
	void modificareRez_UI(int);
	void showAll_UI();

public:
	UI();
	UI(Service&);
	void showUI();
	~UI();

};
