#define LAB2_TEACHER_H
#include <vector>
#include <iostream>
#include "Fio.h"
using namespace std;

class Worker {
	Fio fio;
	int department;
	double salary;
	static int count;

public:
	explicit Worker();
	explicit Worker(char*, char*, char*, int, double);
	explicit Worker(const Worker&);

	//static Worker* search(Worker[], const char*); //����� �� �������
	static void search(Worker[], Fio&); //����� �� �������
	//static vector<Worker>* search(Worker[], Fio);
	static vector<Worker>* filter(Worker[], int); //������ �� ������
	static void sort(Worker[]); //
	static void add(Worker[], const Fio&, int, double);//��������
	static void add(Worker[], const Worker&); //
	friend istream& operator>>(istream&, Worker&);
	friend ostream& operator<<(ostream&, const Worker&); //
	friend int operator== ( Worker&,  Fio& );
	static int get_count() { return count; } //
	static void describe(Worker* pWorker);//
	static void quit(Worker* pWorker); //
};

