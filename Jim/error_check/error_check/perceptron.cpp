#include "multilayer.h"

Layer::Layer(int n)
{
	x.assign((size_t)pow(2, n), std::vector<bool>(n, 0));
	y.assign((size_t)pow(2, n), std::vector<bool>(n, 0));
	transpose_y.assign(n, std::vector<bool>((size_t)pow(2, n), 0));
	w.assign((size_t)pow(2, n), std::vector<double>(n, 0));
	y_idx = 0;
	Layer_level = 1;
	size_t i = 1;
	size_t j = 1;
	while (i < x.size())
	{
		if (x[i - 1] >= x[i])
		{
			while (1)
			{
				if (x[i][x[i].size() - j] == 1)
				{
					x[i][x[i].size() - j] = 0;
					j++;
				}
				else
				{
					x[i][x[i].size() - j] = 1;
					j = 1;
					break;
				}
			}
		}
		else
			i++;
	}
}

void Layer::transpose()
{
	size_t i, j;
	for (i = 0;i < transpose_y.size();i++)
		for (j = 0;j < transpose_y[0].size();j++)
		{
			y[j][i] = transpose_y[i][j];
		}
}

bool Layer::step_h(int bool_idx)
{
	return matrix_product(bool_idx) > 0 ? 1 : 0;
}

bool Layer::sigmoid(long double val)
{
	double result = 1 / (1 + exp(-val));

	return result >= 0.5 ? 1 : 0;
}

double Layer::sigmoid(double val)
{
	return 1 / (1 + exp(-val));
}

double Layer::matrix_product(int bool_idx)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(-0.3, 0.3);
	int row = x.size() / x[0].size();
	double a = 0;
	double b = dist(eng);

	for (int i = 0; i < row;i++)
		a += x[bool_idx][i] * w[i][y_idx];
	a += b;
	
	return a;
}

void Layer::print_activation(int n)
{
	for (size_t i = 0;i < x.size();i++)
	{
		for (size_t j = 0;j < x[0].size();j++)
			std::cout << " " << x[i][j];
		std::cout << "      " << y[i][y_idx] << std::endl;
	}
	std::cout << std::endl << "w" << y_idx << 1 << ": " << w[0][y_idx] << std::endl;
	std::cout << "w" << y_idx << 2 << ": " << w[1][y_idx] << std::endl;
	std::cout << "Layer Level: " << Layer_level << std::endl;
}

Logic_Gate::Logic_Gate(int n)
{
	Expected_val.assign((size_t)pow(2, n), 0);
}

void Logic_Gate::select_gate(int gate, std::vector<std::vector<bool>> x)
{
	this->gate = gate;
	bool result;
	switch (gate)
	{
	case AND:
		gate_str = "AND";
		for (size_t i = 0;i < Expected_val.size();i++)
		{
			result = x[i][0];
			for (size_t j = 1;j < x[0].size();j++)
				result &= x[i][j];
			Expected_val[i] = result;
		}
		break;
	case OR:
		gate_str = "OR";
		for (size_t i = 0;i < Expected_val.size();i++)
		{
			result = x[i][0];
			for (size_t j = 1;j < x[0].size();j++)
				result |= x[i][j];
			Expected_val[i] = result;
		}
		break;
	case NAND:
		gate_str = "NAND";
		for (size_t i = 0;i < Expected_val.size();i++)
		{
			result = x[i][0];
			for (size_t j = 1;j < x[0].size();j++)
				result &= x[i][j];
			Expected_val[i] = !result;
		}
		break;
	case XOR: //(x1 NAND x2) AND (x1 OR x2)
		gate_str = "XOR";
		for (size_t i = 0;i < Expected_val.size();i++)
		{
			result = x[i][0];
			for (size_t j = 1;j < x[0].size();j++)
				result ^= x[i][j];
			Expected_val[i] = result;
		}
		break;
	default:
		break;
	}
}

void Logic_Gate::print_gate()
{
	std::cout << gate_str << " GATE\n" << std::endl;
}

bool Logic_Gate::_isexpect(std::vector<bool> output, int idx)
{
	return Expected_val[idx] == output[idx];
}