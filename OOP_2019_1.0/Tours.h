#pragma once
#include <iostream>
#include "Exceptions.h"

using namespace std;
class Tours
{
public:
	Tours() {};
	Tours(Tours &object1)
	{
		reserv_point = object1.reserv_point;
		int size_n = strlen(object1._get_name());
		name = new char[size_n];
		strcpy(name, object1._get_name());
		int size_c = strlen(object1._get_city());
		city = new char[size_c];
		strcpy(city, object1._get_city());
		days = object1.days;
		price = object1.price;
		identify = object1.identify;
	}

	void func_disp_f();
	void _set_name(char pop[])
	{
		name = pop;
	}
	void _set_city(char pop[])
	{
		city = pop;
	}
	void _set_days(int pop)
	{
		days = pop;
	}
	void _set_price(int pop)
	{
		price = pop;
	}
	char *_get_name()
	{
		return name;
	}
	char *_get_city()
	{
		return city;
	}
	int _get_days()
	{
		return days;
	}
	int _get_price()
	{
		return price;
	}
	int identify;
	bool reserv_point;

	void *operator new (size_t size);
	void operator delete(void *p);

private:
	char *name;
	char *city;
	int days;
	int price;
};
void Tours::func_disp_f()
{
	cout << "Name: " << _get_name() << endl;
	cout << "City: " << _get_city() << endl;
	cout << "Days: " << _get_days() << endl;
	cout << "Price: " << _get_price() << endl;
	cout << "Identificator: " << identify << endl;
	cout << endl;
}
void *Tours::operator new(size_t size)
{
	void *point;
	try {
		point = malloc(size);
		cout << "You call overload operator new! " << endl;
		return malloc(size);

	}
	catch (...)
	{
		cout << "Error, you enter strange data! ";
		abort;
	}
}
void Tours::operator delete(void *point)
{
	free(point);
}

