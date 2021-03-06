// OOP_2019_1.0.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <exception>
#include "string.h"
#include "Conteiner_tours.h"

using namespace std;
/*class exception {
	char * message;
public: 
	exception(char * message) {};

	explicit exception(char const* const _Message) noexcept
	: _Data()

};*/
char *readText()
{
	char *text = (char *)malloc(255);
	char c;
	int numOfChars = 0;
	bool fl_r = true;
	while (fl_r)
	{
		try {
			cin >> text;
			if (strlen(text) > 255) throw value_2;
			while ((c = getchar()) != '\n')
			{
				realloc(text, numOfChars + 1);
				text[numOfChars] = c;
				numOfChars++;
			}
			fl_r = false;
		}
		catch (Char_except&) {
			cout << value_2.what() << endl;
		}
	}
	return text;

}


int main()
{
	exception b;
	cout << "Lets make tours !\n Enter quantity of subjects:" << endl;
	int qant_point;
	bool fl_2 = true;
	while (fl_2)
	{
		try
		{
			cin >> qant_point;
			fl_2 = false;
		}
		catch (int)
		{
			cout << "You enter words! Please, rewrite it in number!" << endl;
		}
	}
	Conten_tours spis(qant_point);
	spis.set_pop_q(qant_point);

	Tours *tour = new Tours[qant_point];
	for (int i = 0; i < qant_point; i++)
	{
		if (i > 0)
			cout << "Next tour" << endl;
		cout << "Enter name: ";
		char *name = readText();

		tour[i]._set_name(name); 

		cout << "Enter city: ";

		char *city = readText();
		tour[i]._set_city(city);

		cout << "Enter days: ";


//////////////////////////////////
		int pop_d;
		bool fl_1 = true;
		while (fl_1) {
			try {
				cin >> pop_d;
				if (pop_d <= 0) {
					throw value_1 ;
				}
				tour[i]._set_days(pop_d);
				fl_1 = false;
			}
			catch (Zero_Negative_except& ) {
				cout << value_1.what() << endl;
			}
			catch (int) {
				cout << "Was entered too many number! Try again!" << endl;
			}
			
		}
/////////////////////		///////////////////////////


		cout << "Enter price: ";
		int pop_p;
		cin >> pop_p;
		tour[i]._set_price(pop_p);


		tour[i].identify = i + 1;
		tour[i].reserv_point = false;
		cout << endl;
	}
	spis.set_pop_tour(tour);

	//реализация меню
	bool stop_button = true;
	while (stop_button)
	{
		cout << "Enter your priority:\n 1 - display affordable tours\n 2 - find a tour\n 3 - book a tour\n 4- display reserve tours" << endl;
		cout << "5 - doing smth with tour \n 0 - exit" << endl;
		short decision;
		cin >> decision;
		switch (decision)
		{
		case 1:
			spis.func_disp();
			break;
		case 2:
			spis.search_s();
			break;
		case 3:
			cout << "Enter identification number of tour: " << endl;
			int id;
			cin >> id;
			spis.reservation(id);
			break;
		case 4:
			spis.reserv_disp();
			break;
		case 0:
			stop_button = false;
			break;
		default:
			cout << "Enter another number!\n"
				<< endl;
			break;
		}
	}

	system("pause");

    return 0;
}

