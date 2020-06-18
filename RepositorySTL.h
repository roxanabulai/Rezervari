
#pragma once
#include "Rezervare.h"
#include <list>

using namespace std;
template<class Elem>

class RepositorySTL
{
private:
	list<Elem> elem;

public:
	RepositorySTL();
	void addItem(Elem);
	int findElem(Elem);
	int delElem(Elem);
	int updateElem(Elem, int, char*, int);
	Elem getItemFromPos(int);
	list<Elem> getAll();
	int dim();
	~RepositorySTL();


};
template<class Elem>
RepositorySTL<Elem>::RepositorySTL()
{
}
template<class Elem>
void RepositorySTL<Elem>::addItem(Elem r) {
	elem.push_back(r);
}
template<class Elem>
int RepositorySTL<Elem>::updateElem(Elem r, int cod, char* nume, int loc) {

	list<Rezervare>::iterator it = find(elem.begin(), elem.end(), r);
	if (it != elem.end()) {
		(*it).setNume(nume);
		it->setCod(cod);
		it->setLoc(loc);
		return 0;
	}
	return -1;

}
template<class Elem>
int RepositorySTL<Elem>::delElem(Elem r) {
	list<Rezervare>::iterator it = find(elem.begin(), elem.end(), r);


	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}
template<class Elem>
int RepositorySTL<Elem>::findElem(Elem r) {
	list<Rezervare>::iterator it = find(elem.begin(), elem.end(), r);
	if (it != elem.end())
		return distance(elem.begin(), it);

	return -1;


}
template<class Elem>
int RepositorySTL<Elem>::dim() {
	return elem.size();
}
template<class Elem>
Elem RepositorySTL<Elem>::getItemFromPos(int i) {

	return elem[i];
}

template<class Elem>
list<Elem> RepositorySTL<Elem>::getAll() {
	return elem;
}
template<class Elem>
RepositorySTL<Elem>::~RepositorySTL()
{
}
