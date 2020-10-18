#define LAB2_PERSON_H
#include <iostream>
using namespace std;
class Fio {
	char* surname;
	char* name;
	char* patronymic;
public:
	explicit Fio(char*, char*, char*);
	Fio();
	int compare(const char* other) const;
	int compare_fio(const Fio& other) const;
	char* get_surname() const { return surname; }
	char* get_name() { return name; }
	char* get_patronymic() { return patronymic; }
	void set_name(char* r) { name = r; }
	void set_surname(char* r) { name = r; }
	void set_patronymic(char* r) { name = r; }
	friend ostream& operator<<(ostream&, const Fio&);
	friend istream& operator>>(istream&, Fio&);
	friend int operator== ( Fio&,  Fio&);

};


