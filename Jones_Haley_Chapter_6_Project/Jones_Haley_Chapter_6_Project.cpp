// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double SQFT_PER_GALLON = 110.0;
const double LABOR_HOURS_PER_GALLON = 8.0;
const double LABOR_RATE_PER_HOUR = 25.0;

int getRooms();

double getSqFt(int roomNum);

double getPricePerGallon(int roomNum);

int gallonsForRoom(double sqft);

void displayEstimate(double paintCharge, int totalGallons, double laborCharge, double totalLaborHours);

int main() {
	int numRooms;
	double totalPaintCharge = 0.0;
	double totalLaborCharge = 0.0;
	int totalGallons = 0;
	double totalLaborHours = 0.0;

	numRooms = getRooms();

	for (int i = 1; i <= numRooms; i++) {
		double sqft = getSqFt(i);
		double pricePerGallon = getPricePerGallon(i);

		int gallons = gallonsForRoom(sqft);
		double laborHours = (sqft / SQFT_PER_GALLON) * LABOR_HOURS_PER_GALLON;
		double paintCost = gallons * pricePerGallon;
		double laborCost = laborHours * LABOR_RATE_PER_HOUR;

		totalGallons += gallons;
		totalPaintCharge += paintCost;
		totalLaborHours += laborHours;
		totalLaborCharge += laborCost;
	}

	displayEstimate(totalPaintCharge, totalGallons, totalLaborCharge, totalLaborHours);

	return 0;
}

int getRooms() {
	int rooms;
	do {
		cout << "Enter number of rooms to be painted (minimum 1): ";
		cin >> rooms;
		if (rooms < 1)
			cout << "Number of rooms must be at least 1.\n";
	} while (rooms < 1);
	return rooms;
}

double getSqFt(int roomNum) {
	double sqft;
	do {
		cout << "Enter square feet for room " << roomNum << ": "
			;
		cin >> sqft;
		if (sqft <= 0)
			cout << "Square footage must be greater than 0.\n";
	} while (sqft <= 0);
	return sqft;
}

double getPricePerGallon(int roomNum) {
	double price;
	do {
		cout << "Enter price per gallon of paint for room " << roomNum << " ($10 minimum: ";
		cin >> price;
		if (price < 10.0)
			cout << "Price must be at least $10.00.\n";
	} while (price < 10.0);
	return price;
 }

int gallonForRoom(double sqft) {

	return static_cast<int>(ceil(sqft / SQFT_PER_GALLON));
}

void displayEstimate(double paintCharge, int totalGallons, double laborCharge, double totalLaborHours) {
	double totalCost = paintCharge + laborCharge;

	cout << fixed << setprecision(2);
	cout << "\nPaint Job Estimate:\n";
	cout << "--------------------\n";
	cout << "Gallons of paint required :" << totalGallons << endl;
	cout << "Hours of labor required:   " << totalLaborHours << endl;
	cout << "Cost of paint:             " << paintCharge << endl;
	cout << "Labor charges:             " << laborCharge << endl;
	cout << "Total cost:                " << totalCost << endl;
}