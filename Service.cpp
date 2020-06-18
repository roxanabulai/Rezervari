#include "Service.h"
#include <list> 
using namespace std;


Service::Service()
{
}
Service::Service(RepositorySTL<Rezervare>& r)
{
	repo = r;
}

void Service::setRepo(RepositorySTL<Rezervare>& r)
{
	repo = r;
}

void Service::addRezervare(Rezervare& r)
{
	repo.addItem(r);
}

int Service::delRezervare(Rezervare& r)
{
	return repo.delElem(r);
}

list<Rezervare> Service::getAll()
{
	return repo.getAll();
	//list<Rezervare> rez=repo.getAll();
	//list<Rezervare> v(rez.begin(),rez.end());
	//return v;
	//deca nu merge ala asta sigur merge;
}

void Service::updateRezervare(Rezervare& r, int c, char* n, int l)
{
	repo.updateElem(r, c, n, l);

}

int Service::findOne(Rezervare& r)
{
	return repo.findElem(r);
}

Service::~Service()
{
}

int Service::functionalitate1(list<Rezervare> rezervari, Rezervare r, int loc_disp)
{
	if (rezervari.size() == 0 && r.getLoc() < loc_disp) return 2; //prima rezervare
	if (r.getLoc() > loc_disp) return -1; //locul dorit nu exista
	if (rezervari.size() != 0) {
		for (Rezervare i : rezervari)
		{
			if (r.getCod() == i.getCod())
				//zborul a mai fost introdus si are unele locuri rezervate
			{
				if (i.getLoc() == r.getLoc())
					return 0;//locul dorit exista dar nu e disp
				return 1;//locul dorit exista si e disp
			}
			else return 1;//zborul nu a mai fost introdus, deci are toate locurile disp
		}
	}
}
int Service::functionalitate2(list<Rezervare>rezervari, Rezervare r, int loc_disp)
{
	int ok = 0;
	for (Rezervare rezv : rezervari)
	{
		if (rezv.getCod() == r.getCod() && rezv.getLoc() == r.getLoc() && strcmp(rezv.getNume(), r.getNume()) == 0)
			ok = 1;//a gasit rezv
	}
	if (ok == 0) //cout << "Nu exista rezervarea data! ";
		return 0;
	return 1;
}