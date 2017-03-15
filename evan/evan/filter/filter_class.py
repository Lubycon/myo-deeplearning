#!/usr/bin/env python

import os
import sys
import csv

class FilterClass:
    def __init__(self, dataUrl):
        self.matrix = []
        f = open(dataUrl, 'r')
        csvReader = csv.reader(f)

        for row in csvReader:
            self.matrix.append(row)

        f.close()

    def getData(self):
        print(self.matrix)
