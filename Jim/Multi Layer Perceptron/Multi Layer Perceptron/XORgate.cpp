#include <iostream>
#include <string>
#include <random>

enum {AND, OR, NAND, XOR}GATE;

class Logic_Gate{
private:
	bool Expected_val[4];
	std::string gate_str;
	
public:
	bool _isexpect(bool output[4], int idx);
	void select_gate(int gate);
	void print_gate();
	int gate;
};

class Layer{
public:
	Layer();
	double w[2][2];
	bool x[2][4];
	bool y[2][4];
	int y_idx;
	int Layer_level;
	bool step_h(int bool_idx);
	void print_step();
};

Layer::Layer()
{
	y_idx = 0;
	Layer_level = 1;
	x[0][0] = 0;
	x[0][1] = 1;
	x[0][2] = 0;
	x[0][3] = 1;
	x[1][0] = 0;
	x[1][1] = 0;
	x[1][2] = 1;
	x[1][3] = 1;
	memset(y, 0, sizeof(y));
}

bool Layer::step_h(int bool_idx)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(-0.3, 0.3);
	int row = sizeof(x) / sizeof(x[0]);
	double a = 0;
	double b = dist(eng);
	for (int i = 0; i < row;i++)
		a += w[y_idx][i] * x[i][bool_idx];
	a += b;
	return a > 0 ? 1 : 0;
}

void Layer::print_step()
{
	for (int i = 0;i < 4;i++)
		std::cout << " " << x[0][i] << "  " << x[1][i] << "      " << y[y_idx][i] << std::endl;
	std::cout << std::endl << "w" << y_idx << 1 << ": " << w[y_idx][0] << std::endl;
	std::cout << "w" << y_idx << 2 << ": " << w[y_idx][1] << std::endl;
	std::cout << "Layer Level: " << Layer_level << std::endl;
}

void Logic_Gate::select_gate(int gate)
{
	this->gate = gate;
	switch (gate)
	{
	case AND:
		gate_str = "AND";
		Expected_val[0] = 0;
		Expected_val[1] = 0;
		Expected_val[2] = 0;
		Expected_val[3] = 1;
		break;
	case OR:
		gate_str = "OR";
		Expected_val[0] = 0;
		Expected_val[1] = 1;
		Expected_val[2] = 1;
		Expected_val[3] = 1;
		break;
	case NAND:
		gate_str = "NAND";
		Expected_val[0] = 1;
		Expected_val[1] = 1;
		Expected_val[2] = 1;
		Expected_val[3] = 0;
		break;
	case XOR: //(x1 NAND x2) AND (x1 OR x2)
		gate_str = "XOR";
		Expected_val[0] = 0;
		Expected_val[1] = 1;
		Expected_val[2] = 1;
		Expected_val[3] = 0;
		break;
	default:
		break;
	}
}

void Logic_Gate::print_gate()
{
	std::cout << gate_str << " GATE\n" << std::endl;
}

bool Logic_Gate::_isexpect(bool output[4], int idx)
{
	return Expected_val[idx] == output[idx];
}


int main(int argc, char** argv)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(-0.3, 0.3);
	Logic_Gate logic;
	Layer layer;
	logic.select_gate(NAND);
	
	
	while (layer.y_idx < 2)
	{
		for (int i = 0;i < 2;i++)
			layer.w[layer.y_idx][i] = dist(eng);

		for (int i = 0;i < 4;)
		{
			layer.y[layer.y_idx][i] = layer.step_h(i);
			if (logic._isexpect(layer.y[layer.y_idx], i))
				i++;
			else
			{
				for (int j = 0;j < sizeof(layer.w) / sizeof(layer.w[0]);j++)
					layer.w[layer.y_idx][j] = dist(eng);
				i = 0;
			}
		}
		logic.print_gate();
		layer.print_step();
		
		logic.select_gate(OR);
		layer.y_idx++;
		std::cout << std::endl;
	}
	logic.select_gate(XOR);
	layer.y_idx = 0;
	layer.Layer_level++;

	memcpy(layer.x, layer.y, sizeof(layer.x));
	for (int i = 0;i < 2;i++)
		layer.w[layer.y_idx][i] = dist(eng);

	for (int i = 0;i < 4;)
	{
		layer.y[layer.y_idx][i] = layer.step_h(i);
		if (logic._isexpect(layer.y[layer.y_idx], i))
			i++;
		else
		{
			for (int j = 0;j < sizeof(layer.w) / sizeof(layer.w[0]);j++)
				layer.w[layer.y_idx][j] = dist(eng);
			i = 0;
		}
	}
	logic.print_gate();
	layer.print_step();
	
	return 0;
}