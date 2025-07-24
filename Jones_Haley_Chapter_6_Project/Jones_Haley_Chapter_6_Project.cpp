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
		}
		if (isHigher(score, maxScore))
	}
}