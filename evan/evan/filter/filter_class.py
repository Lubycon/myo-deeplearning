#!/usr/bin/env python

from __future__ import division
import os
import sys
import csv

import matplotlib as mpl
import matplotlib.pylab as plt

class FilterClass:
    def __init__(self, dataUrl):
        self.currentAverage = 0;
        self.matrix = []
        f = open(dataUrl, 'r')
        csvReader = csv.reader(f)

        for row in csvReader:
            self.matrix.append(row)

        f.close()

    def getData(self):
        axisX = []
        axisY = []
        for i in self.matrix:
            # i[0] = time, i[1] = value
            axisX.append(float(i[0]))
            axisY.append(float(i[1]))

        return [axisX, axisY]

    def AverageFilter(self):
        data = self.getData()
        avgList = []

        for i, v in enumerate(data[1]):
            newAvg = v * (1/(len(avgList) + 1))
            # avg = self.currentAverage + newAvg
            # self.currentAverage = avg;
            # avgList.append(avg)
            # print(avg, v)

        # plt.plot(data[0], data[1])
        # plt.plot(data[0], avgList)
        # plt.show()
