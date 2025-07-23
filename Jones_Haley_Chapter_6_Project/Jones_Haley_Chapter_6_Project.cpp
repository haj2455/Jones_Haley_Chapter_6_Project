// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void getLength_Width(double& lenght, double& width);

double calcPerimeter(double lenght, double width);

double calcArea(double length, double width);

void displayProperties(double perimeter, double area);

// This program gets the length and width of a rectangle, then calculates and displays its perimeter and area.
int main() {
	double length, width, perimeter, area;
	char choice;

	cout << "Rectangle Properties Calculator\n";

	do {
		getLength_Width(length, width);
		// This function prompts the user to enter the length and width of a rectangle and validates the input.It returns both quantities back to the calling function

		// This function takes as input the length and width of a rectangle, calculates the perimeter, and returns the result of the calculation to the caller
		perimeter = calcPerimeter(length, width);
		area = calcArea(length, width);
		// This function takes as input the length and width of a rectangle, calculates the area and returns the area to the caller

		// This function takes as input the perimeter and area of a rectangle and displays these values on the monitor
		displayProperties(perimeter, area);

		// Ask user if they want to continue
		cout << "Do you want to process another rectangle? (Y/N): ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	cout << "Thank you for using the program.\n";
	return 0;
}

// Function Definition
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