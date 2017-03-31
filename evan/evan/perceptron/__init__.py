import random
import os
import sys
import logging

import gate_class as gc
import error_rate as er

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

def getError():
    test = er.ErrorRateClass('data/error/error_data.csv')
    print test.getErrorRate()

getError()
# for i in range(0, limit):
#     run()
