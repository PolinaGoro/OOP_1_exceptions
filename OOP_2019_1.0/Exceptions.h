#pragma once
#include <iostream>

using namespace std;


static class Zero_Negative_except : public exception
{
public:
	//Zero_Negative_except() {}; придеться создавать статический объект
	//имхо базовый класс имеет очень странный конструктор
	virtual const char * what() const throw()
	{
		return "You enter zero or negative value, rewrite!";
	}
}value_1;

static class Char_except : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "You enter too long word, rewrite!";
	}

}value_2;
static class All_except : public exception
{
public: 
	virtual const char * what() const throw()
	{
		return "Entered uncorrect data";
	}
}value_3;
