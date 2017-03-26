import random
import os
import sys
import logging

import gate_class as gc

# TEST
import numpy as np
import matrix as mt
# TEST

logging.basicConfig(level=logging.DEBUG)
limit = 100

def run():
    x1 = random.randrange(0, 2)
    x2 = random.randrange(0, 2)

    w1 = 0.5
    w2 = 0.6

    gate = gc.GateGenerator(w1, w2)

    logging.debug('\n x1=%d\n x2=%d\n w1=%.2f\n w2=%.2f\n'%(x1, x2, w1, w2))
    logging.debug('   AND(%d)  NAND(%d)  OR(%d)  XOR(%d)   '%(gate.AND(x1, x2), gate.NAND(x1, x2), gate.OR(x1, x2), gate.XOR(x1, x2)))
    logging.debug('======================================================')

# for i in range(0, limit):
#     run()

m1 = np.array([[1.0,2.0,3.0],[4.0,5.0,6.0]])
m2 = np.array([[6.0,5.0,4.0],[3.0,2.0,1.0]])

matrix = mt.MatrixClass(m1, m2)
print(m1)
print(m2)
print('=====================')
print('add =>' ,matrix.add())
print('sub =>', matrix.sub())
print('dot =>', matrix.dot())
