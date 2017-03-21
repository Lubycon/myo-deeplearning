#include <iostream>
#include <string>
#include <random>

enum {AND, OR, NAND, XOR}gate_token;

int main(int argc, char** argv)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(-1, 1);

	bool x1[4] = {0, 1, 0, 1};
	bool x2[4] = { 0, 0, 1, 1 };
	double threshold;
	double w1, w2;
	bool y[4];
	bool output[4];
	int gate = AND;
	while (gate <= XOR)
	{
		std::string gate_str;
		switch (gate)
		{
			case AND:
				gate_str = "AND";
				y[0] = 0;
				y[1] = 0;
				y[2] = 0;
				y[3] = 1;
				break;
			case OR:
				gate_str = "OR";
				y[0] = 0;
				y[1] = 1;
				y[2] = 1;
				y[3] = 1;
				break;
			case NAND:
				gate_str = "NAND";
				y[0] = 1;
				y[1] = 1;
				y[2] = 1;
				y[3] = 0;
				break;
			case XOR:
				gate_str = "XOR";
				y[0] = 0;
				y[1] = 1;
				y[2] = 1;
				y[3] = 0;
				break;
			default:
				break;
		}

		threshold = 1;
		w1 = 0.5;
		w2 = 0.3;
		std::cout << gate_str << " Gate" << std::endl;
		std::cout << "\nx1 x2 output" << std::endl;
		for (int i = 0;i < 4;)
		{
			output[i] = w1*x1[i] + w2*x2[i] > threshold ? 1 : 0;
			if (y[i] == output[i])
				i++;
			else
			{
				if (gate == NAND)
				{
					w1 *= -1;
					w2 *= -1;
				}
				threshold = dist(eng);
				i = 0;
			}
		}
		for (int i = 0;i < 4;i++)
		{
			std::cout << " " << x1[i] << "  " << x2[i] << "      " << output[i] << std::endl;
		}

		std::cout << "\nw1 = " << w1 << "\nw2 = " << w2 << "\nthreshold = " << threshold << std::endl;


		system("pause");
		system("cls");
		gate++;
	}
	
	
	return 0;
}