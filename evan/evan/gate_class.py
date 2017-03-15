#!/usr/bin/env python
import logging

class GateGenerator:
    def __init__(self, w1, w2, threshold):
        self.w1 = w1
        self.w2 = w2
        self.threshold = threshold


    def AND(self, x1, x2):
        v1 = x1 * self.w1 >= self.threshold
        v2 = x2 * self.w2 >= self.threshold

        return 1 if v1 and v2 else 0

    def NAND(self, x1, x2):
        v1 = x1 * self.w1 >= self.threshold
        v2 = x2 * self.w2 >= self.threshold

        return 0 if v1 and v2 else 1

    def OR(self, x1, x2):
        v1 = x1 * self.w1 >= self.threshold;
        v2 = x2 * self.w2 >= self.threshold;

        return 1 if v1 or v2 else 0

    def XOR(self, x1, x2):
        v1 = x1 * self.w1 >= self.threshold;
        v2 = x2 * self.w2 >= self.threshold;

        return 1 if v1 != v2 else 0
