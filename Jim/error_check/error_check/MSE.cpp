#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>

int main(int argc, char **argv)
{
	std::ifstream err_data;
	double predict_val = 4;
	double esti_val;
	char delim;
	int size;
	double sum = 0;
	double result;
	std::queue<double> esti_Q;

	if (err_data.is_open()) {
		err_data.close();
	}
	err_data.open("error_data.csv", std::ios::in);

	while (!err_data.eof())
	{
		err_data >> esti_val >> delim;
		esti_Q.push(esti_val);
	}

	size = esti_Q.size();

	while (!esti_Q.empty())
	{
		sum += pow((predict_val - esti_Q.front()), 2);
		esti_Q.pop();
	}
	result = sum / size;

	std::cout << "total error: " << result << std::endl;

	return 0;
}