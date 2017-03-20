INDEX
=====
1. Single Layer Perceptron(AND, OR, NAND)
2. Filter
3. MYO emgdata

Single Layer Perceptron
-
각 케이스에 따라서 실질적으로 나와야 하는 값
'''
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
'''
실 결과 값과 같은 값이 나오지 않을 경우 임계값 랜덤으로 변경
"'
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
"'
