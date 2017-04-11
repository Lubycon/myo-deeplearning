#!/usr/bun/env python

import os
import sys
import csv
import math

import numpy as np

import matplotlib.pyplot as plt

class ErrorRateClass:
    def __init__(self, dataUrl):
        self.time = []
        self.data = []
        self.answer = []

        answerValue = 4.0;

        f= open(dataUrl, 'r')
        reader = csv.reader(f)

        for row in reader:
            for i,v in enumerate(row):
                self.time.append(i)
                self.data.append(float(v))
                self.answer.append(answerValue)

        f.close()

    def renderChart(self):
        plt.plot(self.time, self.data, 's')
        plt.plot(self.time, self.answer, 'rs')

        plt.show()

    def getMSE(self):
        result = 0.0
        for i,v in enumerate(self.data):
            result += ((self.answer[i] - self.data[i])**2)

        return result * 0.5

    def getCEE(self):
        result = 0.0
        for i,v in enumerate(self.data):
            result += (self.data[i] * math.log(self.answer[i]))

        return result * -1;
