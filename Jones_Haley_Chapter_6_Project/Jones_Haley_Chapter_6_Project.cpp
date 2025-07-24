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

	}
}