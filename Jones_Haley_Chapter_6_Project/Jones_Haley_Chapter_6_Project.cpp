// Jones_Haley_Chapter_6_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_JUDGES = 5;

double getScore();

bool isLower(double a, double b);

bool isHigher(double a, double b);

double calcAverage(double total, double minScore, double maxScore);

int main() {
	double score, total = 0.0;
	double minScore, maxScore;

	score = getScore();
	total = score;
	minScore = score;
	maxScore = score;

	for (int i = 1; i < NUM_JUDGES; i++) {
		score = getScore();
		total += score;

		if (isLower(score, minScore)) {
			minScore = score;
		}
		if (isHigher(score, maxScore)) {
			maxScore = score
		}
	}

	double average = calcAverage(total, minScore, maxScore);

	cout << fixed setprecision(2);
	cout << "\nFInal average score (after dropping the highest and lowest): " << average << endl;

	return 0;
}

double getScore() {
	double score;
	do {
		cout << "Enter judge's score (0.0 - 10.0): ";
		cin >> score;
		if (score < 0.0 || score > 10.0) {
			cout << "Invalid input. Score must be between 0 nad 10.\n";
		}
	} while (score < 0.0 || score > 10.0);
	return score;
}

bool isLower(double a, double b) {
	return a <= b;
}

bool isHigher(double a, double b) {
	return a >= b;
}

double calcAverage(double total, double minScore, double maxScore) {
	return (total - minScore - maxScore) / 3.0;
}