/*

Dustin L. Dodson
CS411 - Analysis of Algorithms
Assignment 5
build.cpp

*/

#ifndef _CS_411_HW5_CPP_
#define _CS_411_HW5_CPP_

#include "build.h"

#include <algorithm>
using std::sort;

int getMax(const int & w, const int & e, const vector<vector<int>> & bridges, vector<vector<int>> & weightMatrix) {
	if(weightMatrix[w][e] != -1)
		return weightMatrix[w][e];

	int currentMax = 0;

	for(const auto & bridge : bridges) {
		if(bridge[0] < w && bridge[1] < e) {
			auto possibleMax = getMax(bridge[0], bridge[1], bridges, weightMatrix) + bridge[2];
			
			if(possibleMax > currentMax)
				currentMax = possibleMax;
		}
	}

	weightMatrix[w][e] = currentMax;
	return currentMax;
}

int build(int w, int e, const vector<vector<int>> & bridges) {
	vector<vector<int>> weightMatrix(w + 1, vector<int>(e + 1, -1));

	return getMax(w, e, bridges, weightMatrix);
}

#endif