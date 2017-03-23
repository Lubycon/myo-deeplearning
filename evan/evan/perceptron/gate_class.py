#!/usr/bin/env python
import logging
import numpy as np

import activation as actv

class GateGenerator:
    def __init__(self, w1, w2):
        self.w1 = w1
        self.w2 = w2
        # weight = how much importance it has?
        # b = activation value like theta


    def AND(self, x1, x2):
        x = np.array([x1, x2])
        w = np.array([self.w1, self.w2])
        b = -0.7

        tmp = np.sum(x*w) + b
        func = actv.Activation(tmp)

        return func.step()


    def NAND(self, x1, x2):
        x = np.array([x1, x2])
        w = np.array([self.w1 * -1, self.w2 * -1])
        b = 0.7

        tmp = np.sum(x*w) + b
        func = actv.Activation(tmp)

        return func.step()

    def OR(self, x1, x2):
        x = np.array([x1, x2])
        w = np.array([self.w1, self.w2])
        b = 0

        tmp = np.sum(x*w) + b
        func = actv.Activation(tmp)

        return func.step()

    def XOR(self, x1, x2):
        '''
            x1 -> NAND, OR
            x2 -> NAND, OR
            NAND, OR -> AND
        '''

        x = np.array([x1, x2])

        v1 = self.OR(x1, x2)
        v2 = self.NAND(x1, x2)

        return self.AND(v1, v2)
