#ifndef __LOGIC_GATE__
#define __LOGIC_GATE__

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

enum L_gate{ AND, OR, NAND, XOR };
extern L_gate GATE;

class Logic_Gate {
private:
	std::vector<bool> Expected_val;
	std::string gate_str;
	
public:
	Logic_Gate(int n);
	bool _isexpect(std::vector<bool> output, int idx);
	void select_gate(int gate, std::vector<std::vector<bool>> x);
	void print_gate();
	int gate;
};

#endif