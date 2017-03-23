#!/usr/bin/env python
import logging

import activation

class GateGenerator:
    def __init__(self, w1, w2):
        self.w1 = w1
        self.w2 = w2


    def AND(self, x1, x2):
        # the theta must be bigger than max([x1, x2...,xn])
        v1 = x1 * self.w1
        v2 = x2 * self.w2
        theta = max([v1, v2]) + 0.1

        func = activation.Activation(v1, v2, theta)

        return func.step()


    def NAND(self, x1, x2):
        # the theta must be lower than min([x1, x2...,xn])
        v1 = x1 * (self.w1 * -1)
        v2 = x2 * (self.w2 * -1)
        theta = min([v1, v2]) - 0.1

        func = activation.Activation(v1, v2, theta)

        return func.step()

    def OR(self, x1, x2):
        # the theta must be 0
        v1 = x1 * self.w1
        v2 = x2 * self.w2
        theta = 0;

        func = activation.Activation(v1, v2, theta)

        return func.step()
