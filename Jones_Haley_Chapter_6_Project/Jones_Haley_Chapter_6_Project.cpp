// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void getRegInfo(string& region, int& accidents);

bool isLower(int a, int b);

void showLowest(const string& region, int accidents);

// This program determines the safest driving region in the city based on the number of accidents reported for each region during the past year.
int main() {
	const int NUM_REGIONS = 5;
	string regions[NUM_REGIONS] = { "North", "South", "East", "West", "Central" };
	string regionName, safestRegion;
	int accidents, lowestAccidents;

	for (int i = 1; i < NUM_REGIONS; i++) {
		getRegInfo(regionName, accidents);
		// This function gets the name of a region and the number of accidents that occurred in that region during the past year
		if (isLower(accidents, lowestAccidents)) {
			// This function takes two integer values as input, it returns true if the first value is <= the second value, otherwise it returns false.
			lowestAccidents = accidents;
			safestRegion = regionName;
		}
	}

	showLowest(safestRegion, lowestAccidents);
	// This function gets the name of the region with the lowest reported accidents for the year and the number of accidents for that region.It displays these values on the number.

	return 0;
}

void getRegInfo(string& region, int& accidents) {
	cout << "Enter the name of the region: ";
	cin >> region;

	do {
		cout << "Enter the number of accidents reported in " << region << " last year: ";
		cin >> accidents;
		if (accidents < 0)
			cout << "Accident number must be 0 or more. Try again.\n";
	} while (accidents < 0);
}

bool isLower(int a, int b) {
	return a <= b;
}

void showLowest(const string& region, int accidents) {
	cout << "\nThe safest driving region is: " << region << endl;
	cout << "Number of reported accidents: " << accidents << endl;
}