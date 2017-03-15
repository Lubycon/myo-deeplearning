import random
import os
import sys
import logging

import gate_class

logging.basicConfig(level=logging.DEBUG)
limit = 100

def run():
    x1 = random.randrange(0, 2)
    x2 = random.randrange(0, 2)

    w1 = 1
    w2 = 1

    threshold = 1

    gate = gate_class.GateGenerator(w1, w2, threshold)

    logging.debug('\n x1=%d\n x2=%d\n w1=%f\n w2=%f\n threshold=%d'%(x1, x2, w1, w2, threshold))
    logging.debug('   AND(%d)  NAND(%d)  OR(%d)  XOR(%d)'%(gate.AND(x1, x2), gate.NAND(x1, x2), gate.OR(x1, x2), gate.XOR(x1, x2)))
    logging.debug('======================================================')

for i in range(0, limit):
    run()
