#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

class Filter {
private:
	int SIZE;
	double prefilter[8];
	double pre_front[8];
public:
	Filter(int size);
	double movingavgfilter(int newval, std::queue<int>* Q, int idx);
	double movingavgfilter(double newval, std::queue<double>* Q, int idx);
};