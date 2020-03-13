#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Table_value
{
private:
	vector<double> alfa;
	vector<double> x1;
	vector<double> x2;
public:

	Table_value();
	Table_value(int size);
	~Table_value();

	double get_alfa(int number) const;
	double get_x1(int number) const;
	double get_x2(int number) const;
	
	int get_size() const;

	void set_alfa(int number, double value);
	void set_x1(int number, double value);
	void set_x2(int number, double value);

	void add_row(double alfa, double x1, double x2);

	void print_table() const;

	void print_table_in_file() const;
};

