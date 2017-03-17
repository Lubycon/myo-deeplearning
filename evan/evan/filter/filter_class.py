#!/usr/bin/env python

from __future__ import division
from functools import reduce

import os
import sys
import csv

import matplotlib as mpl
import matplotlib.pylab as plt

class FilterClass:
    def __init__(self, dataUrl):
        self.matrix = []
        self.data = []

        f = open(dataUrl, 'r')
        csvReader = csv.reader(f)

        for row in csvReader:
            self.matrix.append(row)
        self.getData()

        f.close()

    def getData(self):
        axisX = []
        axisY = []
        for i in self.matrix:
            # i[0] = time, i[1] = value
            axisX.append(float(i[0]))
            axisY.append(float(i[1]))

        self.data = [axisX, axisY]

    def averageFilter(self):
        data = self.data
        tmp = []

        for i, v in enumerate(data[1]):
            newAvg = v * (1/(len(tmp) + 1))
            if len(tmp) > 0:
                newAvg = tmp[-1] * (len(tmp) / (len(tmp) + 1))
                newAvg += (v * (1 / (len(tmp) + 1)))
            tmp.append(newAvg)

        plt.plot(data[0], data[1]) #Original Data
        plt.plot(data[0], tmp, 'r') #Average Data
        plt.show()

    def movingAverageFilter(self, size):
        data = self.data
        queue = []
        tmp = []
        firstVal = data[1][0]

        for i, v in enumerate(data[1]):
            queue.append(v)
            if(len(queue) == size):
                queueAvg = sum(queue, 0.0) / size
                queue.pop(0)
                tmp.append(queueAvg)
            else:
                queueAvg = (sum(queue, 0.0) / size) + ((firstVal * (size - len(queue))) / size)
                tmp.append(queueAvg)

        plt.plot(data[0], data[1]) #Original Data
        plt.plot(data[0], tmp, 'r') #Moving Average Data
        plt.show()
