#include "Worker.h"
#include <cstring>
#include <fstream>
#include <iostream>

int Worker::count;

Worker::Worker()
{
	department = 0;
	fio = Fio();
	salary = 0;
	//count++;
}


Worker::Worker( char* surname, char* name, char* patronymic, int _department, double _salary) :
	fio(surname, name, patronymic),
	department(_department),
	salary(_salary) {
	count++;
}


int operator== ( Worker& w1, Fio& f2)
{
	if (w1.fio == f2) return true; else return false;;
}
/*
Worker* Worker::search(Worker* table, const char* query) {
	Worker* current = nullptr;
	for (int i = 0; i < count; i++) {
		current = &table[i];
		if (current->fio.compare(query) == 0)
			break;
	}
	return current;
}*/





/*
vector<Worker>* Worker::search(Worker* table, Fio surname) {
	auto* result = new vector<Worker>;
	for (int i = 0; i < Worker::count; i++) {
		if (table[i].fio == surname)
		//cout << "true" << endl; else cout << "false" << endl;
		//cout << table[i] << endl;
		if (table[i].fio==surname)
		{
			Worker t(table[i]);
			result->push_back(t);
			//cout << "я работаю" << endl;
		}
	}
	return result;
}
*/
vector<Worker>* Worker::filter(Worker * table, int department) {
	auto* result = new vector<Worker>;
	for (int i = 0; i < Worker::count; i++) {
		if (table[i].department == department)
		{
			Worker t(table[i]);
			result->push_back(t);
		}
	}
	return result;
}

void Worker::sort(Worker * table) {
	for (int i = count - 1; i >= 0; i--) {
		for (int j = 0; j < i; ++j) {
			if (table[i].salary < table[j].salary) {
				Worker tmp(table[i]);
				table[i] = table[j];
				table[j] = tmp;
			}
		}
	}
}

void Worker::search(Worker* table,  Fio &f) {
	//Worker* current = nullptr;
	int k = 0;
	for (int i = 0; i < count; i++) {
		//current = &table[i];
		//cout << current[i]<<" что ? " <<f<<endl;
		//if (current[i] == f) { cout << current[i] << endl; k++; }
		//if (table[i] == f) { cout << table[i] << endl; k++; }
		//if (table[i] == f)
		//if (table[i] == f) { cout << table[i] << endl; k++; }
		//break;
	}
	cout << k;

}

istream& operator>>(istream& i, Worker& t)
{
	cout << "¬ведите ‘»ќ\n";
	i >> t.fio;
	cout << "¬ведите номер отдела\n";
	i >> t.department;
	/*while (i.fail() || t.department <= 0)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "ќшибка при вводе номера отдела! ¬ведите ещЄ раз.\n";
		i >> t.department;
	}*/

	cout << "¬ведите оклад\n";

	i >> t.salary;
	/*
	while (i.fail() || t.salary <= 0)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "ќшибка при вводе зарплаты. ¬ведите ещЄ раз.\n";
		i >> t.salary;

		
	}

	*/
	return i;
}

ostream& operator<< (ostream & o, const Worker & t)
{
	o << t.fio << " из отдела є" <<t.department<< " с зарплатой "<< t.salary<<endl;
	return o;
}

void Worker::add(Worker table[], const Fio & p, int _department,  double _salary  ) {
	table[count].salary = _salary;
	table[count].fio = p;
	table[count].department = _department;
	count++;

}

void Worker::add(Worker * table, const Worker & t) {
	table[count ].salary = t.salary;
	table[count ].fio = t.fio;
	table[count ].department = t.department;
	count++;

}


void Worker::describe(Worker * table) {
	for (int i = 0; i < count; ++i) {
		cout << table[i].fio << " отдел є"<<table[i].department;
		cout << " зарплата " << table[i].salary << endl;
	}
}

void Worker::quit(Worker * table) {
	ofstream f;
	f.open("base.txt", ios::out);
	if (f.is_open()) {
		for (int i = 0; i < count; ++i) {
			f << table[i].fio<< " " << table[i].department << " " << table[i].salary << endl;
		}
	}
	f.close();
	//system("pause");
}



Worker::Worker(const Worker & t) {
	salary = t.salary;
	fio = t.fio;
	department = t.department;
}

