#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
#include "multilayer.h"

int main(int argc, char **argv)
{
	std::ifstream err_data;
	double predict_val = 0.1;
	double esti_val;
	char delim;
	double sum = 0;
	double result;
	std::queue<double>esti_Q;
	std::vector<double> esti;
	std::vector<double> predict = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
	Layer lay(0);

	if (err_data.is_open()) {
		err_data.close();
	}
	err_data.open("error_data.csv", std::ios::in);

	while (!err_data.eof())
	{
		err_data >> esti_val >> delim;
		esti_Q.push(esti_val);
	}
	size_t i = 0;
	while (!esti_Q.empty())
	{
		sum += log(lay.sigmoid(esti_Q.front())) * predict[i];
		esti_Q.pop();
		if (i < predict.size() - 1)
			i++;
		else
			i = 0;
	}
	result = -sum;

	std::cout << "total error: " << result << std::endl;

	return 0;
}