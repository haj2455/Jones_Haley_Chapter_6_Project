// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double SQFT_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_RATE_PER_HOUR = 25.0;

int getNumberOfRooms();
double getSquareFeet(int roomNumber);
double getPaintPrice(int roomNumber);
int calculateGallons(double squareFeet);
double calculateLaborHours(double squareFeet);
void displayEstimate(int totalGallons, double totalLaborHours, double totalPaintCost, double totalLaborCost);

int main() {
	int numRooms = getNumberOfRooms();

	int totalGallons = 0;
	double totalLaborHours = 0.0;
	double totalPaintCost = 0.0;
	double totalLaborCost = 0.0;

	for (int i = 1; i <= numRooms; i++) {
		double sqft = getSquareFeet(i);
		double pricePerGallon = getPaintPrice(i);

		int gallons = calculateGallons(sqft);
		double laborHours = calculateLaborHours(sqft);
		double paintCost = gallons * pricePerGallon;
		double laborCost = laborHours * LABOR_RATE_PER_HOUR;

		totalGallons += gallons;
		totalLaborHours += laborHours;
		totalPaintCost += paintCost;
		totalLaborCost += laborCost;
	}

	displayEstimate(totalGallons, totalLaborHours, totalPaintCost, totalLaborCost);

	return 0;
}

int getNumberOfRooms() {
	int rooms;
	do {
		cout << "Enter number of rooms to be painted (must be at least 1): ";
		cin >> rooms;
		if (rooms < 1) {
			cout << "ERROR: Number of rooms must be 1 or more.\n";
		}
	} while (rooms < 1);
	return rooms;
}

double getSquareFeet(int roomNumber) {
	double sqft;
	do {
		cout << "Enter square feet of wall space for room " << roomNumber << ": ";
		cin >> sqft;
		if (sqft <= 0) {
			cout << "ERROR: Square feet must be greater than 0.\n";
		}
	} while (sqft <= 0);
	return sqft;
}

double getPaintPrice(int roomNumber) {
	double price;
	do {
		cout << "Enter price per gallon of paint for room " << roomNumber << " ($10.00 or more): ";
		cin >> price;
		if (price < 10.0) {
			cout << "ERROR: Paint price must be at least $10.00.\n";
		}
	} while (price < 10.0);
	return price;
}

int calculateGallons(double squareFeet) {
	return static_cast<int>(ceil(squareFeet / SQFT_PER_GALLON));
}

double calculateLaborHours(double squareFeet) {
	return (squareFeet / SQFT_PER_GALLON) * HOURS_PER_GALLON;
}

void displayEstimate(int totalGallons, double totalLaborHours, double totalPaintCost, double totalLaborCost) {
	double totalCost = totalPaintCost + totalLaborCost;

	cout << fixed << setprecision(2);
	cout << "\n--- Paint Job Estimate ---\n";
	cout << "Gallons of paint required: " << totalGallons << endl;
	cout << "Hours of labor required:   " << totalLaborHours << endl;
	cout << "Cost of the paint:        $" << totalPaintCost << endl;
	cout << "Labor charges:            $" << totalLaborCost << endl;
	cout << "-------------------------------\n";
	cout << "Total cost of the paint job: $" << totalCost << endl;
}