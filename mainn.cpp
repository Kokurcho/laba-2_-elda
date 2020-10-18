#include <iostream>
#include <cstring>
#include "Worker.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
const int COUNT_OF_RECORDS = 1000;
void load_base(Worker*);

int main() {
	setlocale(LC_ALL, "Russian");
	Worker* table = new Worker[COUNT_OF_RECORDS];

	cout << "��������� ����? 1 - ��, 0 - ���" << endl;
	int choice = 0;
	cin >> choice;
	while (cin.fail() || choice < 0 || choice > 1)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "������ �����. ���������� �����.\n";
		cin >> choice;
	}
	if (choice == 1) load_base(table);

	int command = 0;

	for (int i = 0; i < COUNT_OF_RECORDS; i++)
	{
		
		cout << "\n������� ����� �������\n";
		cout << "1 - �������� ��������\n";
		cout << "2 - ����� �������� �� �������\n";
		cout << "3 - ������ �� ������\n";
		cout << "4 - ����������� ���� ������\n";
		cout << "5 - ����������� �� ��������\n";
		cout << "6 - ����� � ���������\n";
		cin >> command;
		while (cin.fail() || command <= 0 || command > 6)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cout << "Failed on entering command! Try again.\n";
			cin >> command;
		}
		switch (command)
		{
		case 1:
		{
			/*
			cout << "������� ���\n";
			Fio fio;
			cin >> fio;

			cout << "������� ����� ������\n";
			int department = 1;
			cin >> department;
			while (cin.fail() || department <= 0)
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				cout << "������ ��� ����� ������ ������! ������� ��� ���.\n";
				cin >> department;
			}

			cout << "������� �����\n";
			double salary = 0;
			cin >> salary;
			while (cin.fail() || salary <= 0)
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				cout << "������ ��� ����� ��������. ������� ��� ���.\n";
				cin >> salary;
			}
			*/
			Worker w;
			cin >> w;
			//Worker::add(table, department, fio, salary);
			Worker::add(table, w);
			break;
		}
		/*case 2:
		{
			if (Worker::get_count() < 1)
			{
				cout << "���� ������ �����.\n";
				break;
			}
			cout << "������� ������� ��������:.\n";
			string p1;
			cin >> p1;
			char* p = new char[p1.size() + 1];
			copy(p1.begin(), p1.end(), p);
			p[p1.size()] = '\0';
			cout << *Worker::search(table, p);
			break;

		}*/
		case 2:
		{
			if (Worker::get_count() < 1)
			{
				cout << "���� ������ �����.\n";
				break;
			}
			cout << "������� ������� ��������:.\n";
			string p1;
			cin >> p1;
			char* p = new char[p1.size() + 1];
			copy(p1.begin(), p1.end(), p);
			p[p1.size()] = '\0';
			Fio f(p, p, p);
			Worker::search(table, f);
			break;

		}
		/*case 2:
		{
			if (Worker::get_count() < 1)
			{
				cout << "���� ������ �����.\n";
				break;
			}
			cout << "������� ������� ��������:\n";
			string p1;
			cin >> p1;

			char* p = new char[p1.size() + 1];
			copy(p1.begin(), p1.end(), p);
			p[p1.size()] = '\0';

			Fio example(p, p, p);
			Worker ex2(p, p, p, 2, 2);
			if (ex2 == example) cout << 1 <<endl;

			int k = 0;
			auto* vect = Worker::search(table, example);
			for (Worker& q : *vect)
			{
				cout << q; k++;
			}
			if (k == 0) cout << "��� ������� � ����� ��������" << endl;
			break;
		}
		*/
		case 3:
		{
			if (Worker::get_count() < 1)
			{
				cout << "���� ������ �����.\n";
				break;
			}
			int department = 0; //������ �� ������
			cout << "������� ����� ������ ��� ����������:\n";
			cin >> department;
			while (cin.fail() || department < 0)
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				cout << "������ ��� ����� ������ ������. ���������� ��� ���.\n";
				cin >> department;
			}
			// ����� ������

			auto* vec = Worker::filter(table, department);
			for (Worker& q : *vec)
				cout << q;
			break;

		}
		case 4:
			if (Worker::get_count() > 0)
				Worker::describe(table);
			else cout << "���� ������ �����.\n";
			break;
		case 5:
			if (Worker::get_count() > 1)
				Worker::sort(table);
			else cout << "���� ������ �� ������������. (((\n";
			break;
		case 6:
			Worker::quit(table);
			goto end;
		}
	}
end:
	char* name = new char[100];
	char* surname = new char[100];
	char* patronymic = new char[100];
	strcpy(name, "a");
	strcpy(surname, "b");
	strcpy(patronymic, "c");
	Fio p(name, surname, patronymic);

	int count = Worker::get_count();
	if (count == 0)
	{
		Worker t(name, surname, patronymic, 1, 2);
		cout << "��� ���������. �������� ������� �� ���������\n";
		Worker::add(table, t);
		Worker::describe(table);
		Worker::quit(table);
	}
	//int a = Worker::get_count();
	else cout << "\n������� " << Worker::get_count() << " ���������"<<endl;;
	system("pause");
	return 0;
}


void load_base(Worker* table)
	{
		ifstream file("base.txt");

		if (file.is_open())
		{
			cout << "���� ������." << endl;

			string line;


			while (getline(file, line))
			{

				string name_, surname_, patronymic_;
				int department_;
				double salary_;

				istringstream iss(line);

				iss >> surname_ >> name_ >> patronymic_ >> department_ >> salary_;

				char* surname = new char[surname_.size() + 1];
				copy(surname_.begin(), surname_.end(), surname);
				surname[surname_.size()] = '\0';

				char* name = new char[name_.size() + 1];
				copy(name_.begin(), name_.end(), name);
				name[name_.size()] = '\0';

				char* patronymic = new char[patronymic_.size() + 1];
				copy(patronymic_.begin(), patronymic_.end(), patronymic);
				patronymic[patronymic_.size()] = '\0';
				cout << surname << " " << name << " " << patronymic << " " << department_ << " " << salary_ << endl;
				Fio p(surname, name, patronymic);

				Worker::add(table,  p, department_, salary_);

			}
		}
		else
		{
			cout << "�� ������� ������� ����." << endl;
		}
	}

