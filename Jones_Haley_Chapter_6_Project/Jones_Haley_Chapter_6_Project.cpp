// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void getLength_Width(double& lenght, double& width);

double calcPerimeter(double lenght, double width);

double calcArea(double length, double width);

void displayProperties(double perimeter, double area);

int main() {
	double length, width, perimeter, area;
	char choice;

	cout << "Rectangle Properties Calculator\n";

	do {
		getLength_Width(length, width);

		perimeter = calcPerimeter(length, width);
		area = calcArea(length, width);

		displayProperties(perimeter, area);

		cout << "Do you want to process another rectangle? (Y/N): ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	cout << "Thank you for using the program.\n";
	return 0;
}

void getLength_Width(double& length, double& width) {
	do {
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		if (length <= 0)
			cout << "Length must be greater than 0.\n";
	} while (length <= 0);
}

double calcPerimeter(double length, double width) {
	return 2 * (length + width);
}

double calcArea(double length, double width) {
	return length * width;
}

void displayProperties(double perimeter, double area) {
	cout << "Perimeter of the rectangle: " << perimeter << endl;
	cout << "Area of the rectangle: " << area << endl;
}