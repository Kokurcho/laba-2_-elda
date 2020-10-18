#include "Fio.h"
#include <cstring>
Fio::Fio(char* _surname, char* _name, char* _patronymic) : surname(_surname), name(_name), patronymic(_patronymic) {

}

Fio::Fio() {
	surname = new char[0];
	name = new char[0];
	patronymic = new char[0];
}

int operator== (Fio& f1, Fio& f2)
{
	if (f1.surname == f2.surname) return true; else return false;
};

int Fio::compare(const char* other) const { //сравнение для сортировки
	return strcmp(surname, other) ;
}

int Fio::compare_fio(const Fio& other) const { //сравнение для сортировки
	return strcmp(surname, other.surname)+ strcmp(name, other.name)+ strcmp(patronymic, other.patronymic);
}

ostream& operator<<(ostream& o, const Fio& p) {
	return o << p.surname << " " << p.name << " " << p.patronymic;
}

istream& operator>>(istream& i, Fio& p) {
	i >> p.surname;
	i >> p.name;
	i >> p.patronymic;
	return i;
}

