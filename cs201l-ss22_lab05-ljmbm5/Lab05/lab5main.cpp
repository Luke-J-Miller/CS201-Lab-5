//Luke Miller ljmbm5@umsystem.edu  Lab 5
#include <iostream>
#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
#include <limits>
#include <cstring>  // tools for working with character arrays
#include <cctype> // tools for working with strings isalpha(), toupper, etc
#include "lab5fn.h"  
#include <fstream>
#include <vector>
#include<Windows.h>
using namespace std;


int main() {
	vector<vector<double>> coordinates;
	vector<double> coordinate;
	vector<double> distances;
	ifstream inFS;


	inFS.open("C:\\Users\\mille\\source\\repos\\cs201l-ss22_lab05-ljmbm5\\input.txt");
	try {
		if (!inFS.is_open()) {
			throw (runtime_error("Could not open input file"));
		}
	}
	catch (runtime_error& e) {
		cout << e.what();
	}
	int count = 0;
	double x;
	while (!inFS.eof()) {
		for (int j = 0; j < 6; j++) {
			inFS >> x;
			coordinate.push_back(x);
		}
		coordinates.push_back(coordinate);
		coordinate.clear();
	}
	ofstream outFS;
	outFS.open("C:\\Users\\mille\\source\\repos\\cs201l-ss22_lab05-ljmbm5\\output.txt");
	try {
		if (!outFS.is_open()) {
			throw (runtime_error("Could not open output file"));
		}
	}
	catch (runtime_error& e) {
		cout << e.what();
	}
	for (int i = 0; i < coordinates.size(); i++) {
		double y = calcDistance(coordinates[i][0], coordinates[i][1], coordinates[i][2],
			coordinates[i][3], coordinates[i][4], coordinates[i][5]);
		distances.push_back(y);
	}
	double temp;
	for (int i = 0; i < distances.size() - 1; i++) {
		int indexSmallest = i;
		for (int j = i + 1; j < distances.size(); j++) {
			if (distances[j] < distances[indexSmallest]) {
				indexSmallest = j;
			}
		}
		temp = distances[i];
		distances[i] = distances[indexSmallest];
		distances[indexSmallest] = temp;
	}
	for (int i = 0; i < distances.size(); i++) {
		outFS << distances[i] << endl;
	}
	inFS.close();
	outFS.close();
	return 0;
}


