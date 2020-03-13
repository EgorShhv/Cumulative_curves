#include "Table_value.h"

Table_value::Table_value()
{}

Table_value::Table_value(int size)
{
	alfa.resize(size, 0);
	x1.resize(size, 0);
	x2.resize(size, 0);
}

Table_value::~Table_value()
{}

double Table_value::get_alfa(int number) const
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	return alfa[number];
}

double Table_value::get_x1(int number) const
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	return x1[number];
}

double Table_value::get_x2(int number) const
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	return x2[number];
}

int Table_value::get_size() const
{
	return alfa.size();
}

void Table_value::set_alfa(int number, double value)
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	alfa[number] = value;
}

void Table_value::set_x1(int number, double value)
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	x1[number] = value;
}

void Table_value::set_x2(int number, double value)
{
	if (number < 0 || number >= alfa.size())
	{
		throw exception("Out of range");
	}
	x2[number] = value;
}

void Table_value::print_table() const
{
	cout << "alf\tx1\tx2\n";
	
	for (int i = 0; i < alfa.size(); i++)
	{
		cout << alfa[i] << "\t" << x1[i] << "\t" << x2[i] << "\n";
	}
}

void Table_value::print_table_in_file() const
{
	ofstream file1("first_graph1.txt"), file2("second_graph1.txt");

	for (int i = 0; i < alfa.size(); i++)
	{
		file1 << alfa[i] << "\t" << x1[i] << "\n";
		file2 << alfa[i] << "\t" << x2[i] << "\n";
	}

	file1.close();
	file2.close();
}

// Сделать хорошо
void Table_value::add_row(double alfa, double x1, double x2)
{
	this->alfa.push_back(alfa);
	this->x1.push_back(x1);
	this->x2.push_back(x2);
}


/*------------------------------------------------------------\
|                                                               |
|                   f(x)=x^a, f(x)c[0,1]                        |
|                                                               |
|   /|\ y = f(x)                                                |
|    |                                                          |
|  1-|- - - - - - - - - - - - - - __                            |
| y2-| - - - - - - - - - ________/  |                           |
|    |             ____/|           |                           |
| y1-|- - - - -___/     |           |                           |
|    |       _/|        |           |                           |
|    |     _/  |        |     C     |                           |
|    |    /    |   B    |           |                           |
|    |   /     |        |           |                           |
|    |  |   A  |        |           |                           |
|    | /       |        |           |                           |
|    |/________|________|___________|_______ >                  |
|   0         x1       x2           1        x                  |
|                                                               |
|                                                               |
|   S(A) = 1/2 * (0,x1) * (x1,y1)                               |
|                                                               |
|   S(B) = 1/2 * [(x1,y1) + (x2,y2)] * (x1,x2)                  |
|                                                               |
|   S(C) = 1/2 * [(x2,y2) + (1,1)] * (x2,1)                     |
|                                                               |
|                                                               |
|   S = S(A) + S(B) + S(C)                                      |
|                                                               |
|   S --> max                                                   |
|                                                               |
\--------------------------------------------------------------*/