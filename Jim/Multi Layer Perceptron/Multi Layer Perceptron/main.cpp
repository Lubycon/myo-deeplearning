#include "multilayer.h"

L_gate GATE;

int main(int argc, char** argv)
{
	int n;
	std::cout << "Input: ";
	std::cin >> n;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(-0.3, 0.3);
	Logic_Gate logic(n);
	Layer layer(n);
	logic.select_gate(NAND, layer.x);


	while (layer.y_idx < 2)
	{
		for (int i = 0;i < (int)pow(2, n);i++)
			layer.w[i][layer.y_idx] = dist(eng);

		for (int i = 0;i < (int)pow(2, n);)
		{
			layer.transpose_y[layer.y_idx][i] = layer.step_h(i);
			if (logic._isexpect(layer.transpose_y[layer.y_idx], i))
				i++;
			else
			{
				for (size_t j = 0;j < layer.w.size() / layer.w[0].size();j++)
					layer.w[layer.y_idx][j] = dist(eng);
				i = 0;
			}
		}
		layer.transpose();
		logic.print_gate();
		layer.print_activation(n);

		logic.select_gate(OR, layer.x);
		layer.y_idx++;
		std::cout << std::endl;
	}
	logic.select_gate(XOR, layer.x);
	layer.y_idx = 0;
	layer.Layer_level++;

	layer.x = layer.y;
	for (int i = 0;i < (int)pow(2, n);i++)
		layer.w[i][layer.y_idx] = dist(eng);

	for (int i = 0;i < (int)pow(2, n);)
	{
		layer.transpose_y[layer.y_idx][i] = layer.step_h(i);
		if (logic._isexpect(layer.transpose_y[layer.y_idx], i))
			i++;
		else
		{
			for (size_t j = 0;j < layer.w.size() / layer.w[0].size();j++)
				layer.w[layer.y_idx][j] = dist(eng);
			i = 0;
		}
	}
	layer.transpose();
	logic.print_gate();
	layer.print_activation(n);

	return 0;
}