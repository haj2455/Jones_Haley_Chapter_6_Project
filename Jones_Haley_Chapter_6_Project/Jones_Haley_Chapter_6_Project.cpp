// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_F = 0;
const int MAX_F = 20;

double getCelsius(int fahrenheit);

// This program produces a table showing degrees Fahrenheit between the values of 0 and 20 with the corresponding Celsius value.The table has a title, the columns are labeled,and the temperature values are right aligned in each column.Temperature values are displayed with one decimal point of precision.
int main() {
	cout << "Temperature Conversion Table\n";
	cout << setw(10) << "Fahrenheit" << setw(15) << "Celsius\n";
	cout << "-----------------------------\n";

	for (int f = MIN_F; f <= MAX_F; ++f) {
		double c = getCelsius(f);
		cout << setw(10) << f << setw(15) << fixed << setprecision(1) << c << endl;
	}

	return 0;
}

// This takes as input a temperature value in degrees Fahrenheit and returns the equivalent value of the temperature in degrees Celsius
double getCelsius(int fahrenheit) {
	return (5.0 / 9.0) * (fahrenheit - 32);
}