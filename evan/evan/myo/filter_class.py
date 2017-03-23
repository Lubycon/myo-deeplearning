#!/usr/bin/env python

from __future__ import division

import os
import sys
import csv

class FilterClass:
    def __init__(self, time, value, title):
        self.time = time
        self.value = value
        self.title = title

    def averageFilter(self):
        data = self.data
        tmp = []

        # for i, v in enumerate(data[1]):
        #     newAvg = v * (1/(len(tmp) + 1))
        #     if len(tmp) > 0:
        #         newAvg = tmp[-1] * (len(tmp) / (len(tmp) + 1))
        #         newAvg += (v * (1 / (len(tmp) + 1)))
        #     tmp.append(newAvg)
        #

    def getMAData(self, size):
        time = self.time
        value = self.value

        tmp = []

        firstVal = float(value[0])
        queue = [firstVal for i in range(size)]

        for i, v in enumerate(value):
            v = float(v)

            queue.append(v)
            queue.pop(0)

            if(len(queue) == size):
                avg = sum(queue, 0.0) / size
                tmp.append(avg)

        return {
            'origin': [time, value],
            'filtered': [time, tmp]
        }
