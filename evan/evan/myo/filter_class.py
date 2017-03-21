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
        time = []
        values = [[] for _ in range(len(self.matrix[0]))]

        for i, v in enumerate(self.matrix):
            for ii,vv in enumerate(v):
                values[ii].append(vv)

        self.data = values

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
        test = []

        time = data.pop(0)
        time.pop(0)
        for i in data:
            print(i)

        for i, v in enumerate(data):
            title = v.pop(0)
            firstVal = float(v[0])

            for ii, vv in enumerate(v):
                vv = float(vv)
                if(vv < 0):
                    vv = (vv**2)**0.5

                queue.append(vv)
                test.append(vv)
                if(len(queue) == size):
                    queueAvg = sum(queue, 0.0) / size
                    queue.pop(0)
                    tmp.append(queueAvg)
                else:
                    queueAvg = (sum(queue, 0.0) / size) + ((firstVal * (size - len(queue))) / size)
                    tmp.append(queueAvg)

            plt.plot(time, test)
            plt.plot(time, tmp, 'r')
            plt.title(title)
            # plt.show()
