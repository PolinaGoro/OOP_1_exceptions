// OOP_2019_1.0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include "string.h"

using namespace std;
/*class exception {
	char * message;
public: 
	exception(char * message) {};

	explicit exception(char const* const _Message) noexcept
	: _Data()

};*/

class Int_except : public exception
{
public:
	virtual const char * what() const throw()
	{
		return "You enter zero or negative value, rewrite!";
	}
}value;
class Double_except : exception
{
	Double_except() {}


};
class Char_except : exception
{
	Char_except() {}


};
class All_except : exception
{
	All_except() {}

};

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

class Conten_tours
{
private:
	int pop_q;
	Tours *pop_tour;

public:
	void set_pop_q(int pop)
	{
		pop_q = pop;
	}

	int get_pop_q()
	{
		return pop_q;
	}

	void set_pop_tour(Tours *popich)
	{
		for (int i = 0; i < pop_q; i++)
		{
			pop_tour[i] = popich[i];
		}
	}

	Tours get_pop_tour(int i)
	{
		return pop_tour[i];
	}

	void search_s(); // ïðîèçâîäèò ïîèñê ïî 4 ïîëÿì
	void search_s(char *pop_n, char *pop_c, char *pop_d, char *pop_p);
	void search_s(Tours searchTour);
	void reservation(int ent_ident); // ôóíêöèÿ áðîíèðîâàíèÿ(áðîíèðóåò ïî èäåíòèôèêàòîðó)
	void func_disp();
	void reserv_disp();
	char *cin(int size);
	char *cin();

	Conten_tours(int q) : pop_q(q), pop_tour(new Tours[q])
	{
	}
};

char *Conten_tours::cin(const int size)
{
	char *list = new char[size];
	int i = 0;
	char input;
	while (i < size)
	{
		input = getchar();
		if (input == '\n')
		{
			list[i] = '\0';
			break;
		}
		list[i] = input;
		i++;
	}
	char *time_str = new char[strlen(list) + 1];
	strcpy(time_str, list);
	return time_str;
}

char *Conten_tours::cin()
{
	return cin(100);
}

void Conten_tours::search_s()
{
	const size_t size = 100;
	char *s = cin(size); // çàãëóøêà äëÿ òîãî ÷òîáû ðàáîòàë ââîä
	cout << "Now let's search your tour!\n";
	cout << "Enter name for searching: ";
	char *pop_n = cin(size);
	cout << "Enter city for searching: ";
	char *pop_c = cin(size);
	cout << "Enter days for searching: ";
	char *pop_d = cin(size);
	cout << "Enter price for searching: ";
	char *pop_p = cin(size);
	search_s(pop_n, pop_c, pop_d, pop_p);
}

void Conten_tours::search_s(char *pop_n, char *pop_c, char *pop_d, char *pop_p)
{
	Tours searchTour;
	searchTour._set_name(pop_n);
	searchTour._set_city(pop_c);
	searchTour._set_days(atoi(pop_d));
	searchTour._set_price(atoi(pop_p));
	search_s(searchTour);
}

void Conten_tours::search_s(Tours searchTour) // ïðîèçâîäèò ïîèñê ïî 4 ïîëÿì
{
	char *searchName = { searchTour._get_name() };
	char *searchCity = { searchTour._get_city() };
	int searchCounter = 0;

	if (!(searchName[0] == '\0'))
	{
		searchCounter++;
	}
	if (!(searchCity[0] == '\0'))
	{
		searchCounter++;
	}
	if (!(searchTour._get_days() == 0))
	{
		searchCounter++;
	}
	if (!(searchTour._get_price() == 0))
	{
		searchCounter++;
	}

	for (int i = 0; i < pop_q; i++)
	{
		int counter = 0;
		char *name = { pop_tour[i]._get_name() };
		char *city = { pop_tour[i]._get_city() };
		if (strcmp(searchName, name) == 0)
		{
			counter++;
		}
		if (strcmp(searchCity, city) == 0)
		{
			counter++;
		}
		if (searchTour._get_days() == pop_tour[i]._get_days())
		{
			counter++;
		}
		if (searchTour._get_price() == pop_tour[i]._get_price())
		{
			counter++;
		}
		if (searchCounter == counter)
		{
			cout << "Naideno!\n";
			pop_tour[i].func_disp_f();
		}
	}
}

void Conten_tours::reservation(int ent_ident) // ôóíêöèÿ áðîíèðîâàíèÿ(áðîíèðóåò ïî èäåíòèôèêàòîðó)
{
	for (int i = 0; i < get_pop_q(); i++)
	{
		if (ent_ident == pop_tour[i].identify)
		{
			pop_tour[i].reserv_point = true;
			cout << "Your rezervation is suckcess!" << endl;
		}
	}
	//åñëè òàêîãî èäåíòèôèêàòîðà íåò
	cout << "This number is not in the card index. Enter exiting identifier!" << endl;
}

void Conten_tours::reserv_disp()
{
	for (int i = 0; i < get_pop_q(); i++)
	{
		if (pop_tour[i].reserv_point == true)
			pop_tour[i].func_disp_f();
	}
}

void Conten_tours::func_disp()
{
	cout << "Let's watch on tour!" << endl;
	for (int i = 0; i < get_pop_q(); i++)
	{
		int ii = i;
		cout << "Tour:" << ii + 1 << endl;
		cout << "Name: " << get_pop_tour(i)._get_name() << endl;
		cout << "City: " << get_pop_tour(i)._get_city() << endl;
		cout << "Days: " << get_pop_tour(i)._get_days() << endl;
		cout << "Price: " << get_pop_tour(i)._get_price() << endl;
		cout << "Identificator: " << pop_tour[i].identify << endl;
		cout << endl;
	}
}

char *readText()
{
	char *text = (char *)malloc(255);
	char c;
	int numOfChars = 0;
	try {
		cin >> text;
		while ((c = getchar()) != '\n')
		{
			realloc(text, numOfChars + 1);
			text[numOfChars] = c;
			numOfChars++;
		}
		return text;
	}
	catch(char*){
		cout << "Too many size of char's array." << endl;
	}
}


int main()
{
	exception b;
	cout << "Lets make tours !\n Enter quantity of subjects:" << endl;
	int qant_point;
	cin >> qant_point;
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
					throw value; 
				}
				tour[i]._set_days(pop_d);
				fl_1 = false;
			}
			catch (Int_except& value) {
				cout << value.what() << endl;
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

