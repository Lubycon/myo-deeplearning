#!/usr/bin/env python

import os
import sys
import csv

import filter_class as ft


import matplotlib.pyplot as plt


class EMGClass:
    def __init__(self, dataUrl):
        self.matrix = []
        self.data = []

        f = open(dataUrl, 'r')
        csvReader = csv.reader(f)

        for row in csvReader:
            self.matrix.append(row)
        self.generateData()

        f.close()

    def generateData(self):
        values = [[] for _ in range(len(self.matrix[0]))]

        for i, v in enumerate(self.matrix):
            for ii,vv in enumerate(v):
                values[ii].append(vv)

        self.data = values

    def getMAFilter(self, size):
        data = self.data

        time = data.pop(0)
        time.pop(0)

        gesture = data.pop(-1)
        gesture.pop(0)
        for i,v in enumerate(gesture):
            gesture[i]  = float(v) * 50

        for i, v in enumerate(data):
            title = v.pop(0)

            v = self.removeNagative(v)

            f = ft.FilterClass(time, v, title)
            fData = f.getMAData(size)

            plt.subplot(4, 2, i + 1)
            plt.title(title + '(size: ' + str(size) + ')')
            plt.plot(fData['origin'][0], fData['origin'][1]) # Original
            plt.plot(fData['filtered'][0], fData['filtered'][1], 'r') # Filtered
            plt.plot(time, gesture, 'y') # Gesture
            plt.ylim(0, 256)
            plt.xlim(len(time))
            plt.plot(time, gesture)

        plt.show()

    def removeNagative(self, data):
        tmp = []
        for v in data:
            v = (float(v)**2)**0.5
            tmp.append(v)

        return tmp
