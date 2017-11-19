/*

Dustin L. Dodson
CS411 - Analysis of Algorithms
Assignment 5
build.h

*/

#ifndef _CS_411_HW5_H_
#define _CS_411_HW5_H_

#include <vector>
using std::vector;

int buildRecursive(int w, int e, const vector<vector<int>> &bridges, vector<vector<int>> &bridgeTollLookup);
int build(int w, int e, const vector<vector<int>> &bridges);

#endif