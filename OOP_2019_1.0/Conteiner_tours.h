#pragma once
#include "Tours.h"
#include <iostream>

using namespace std;

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


