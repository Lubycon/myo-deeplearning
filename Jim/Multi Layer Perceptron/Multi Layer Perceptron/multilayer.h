#ifndef __MULTI_LAYER__
#define __MULTI_LAYER__

#include "logicgate.h"

class Layer {
public:
	Layer(int n);
	std::vector<std::vector<double>> w;
	std::vector<std::vector<bool>> x;
	std::vector<std::vector<bool>> y;
	std::vector<std::vector<bool>> transpose_y;
	int y_idx;
	int Layer_level;
	bool step_h(int bool_idx);
	void print_activation(int n);
	void transpose();
	double matrix_product(int bool_idx);
};

#endif