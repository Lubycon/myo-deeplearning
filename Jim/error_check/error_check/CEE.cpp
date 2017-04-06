#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
	std::ifstream err_data;
	double predict_val = 4;
	double esti_val;
	char delim;
	double sum = 0;
	double result;
	std::vector<double> esti;
	std::vector<double> predict;

	if (err_data.is_open()) {
		err_data.close();
	}
	err_data.open("error_data.csv", std::ios::in);

	while (!err_data.eof())
	{
		err_data >> esti_val >> delim;
		esti_Q.push(esti_val);
	}
	while (!esti_Q.empty())
	{
		sum += (log(predict_val) / log(2)); //밑이 2인 로그함수
		//esti_Q.pop();
	}
	result = -sum;

	std::cout << "total error: " << result << std::endl;

	return 0;
}