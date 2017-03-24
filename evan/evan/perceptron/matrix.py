import numpy as np

class MatrixClass:
    def __init__(self, m1, m2):
        self.m1 = m1
        self.m2 = m2

    def dot(self):
        m1 = self.m1
        m2 = self.m2




    def add(self):
        m1 = self.m1
        m2 = self.m2

        if self.sizeMatchValidator(m1, m2) != True:
            return 'matrix size Error'

        m3 = np.zeros((len(m1[0]), len(m1)))

        for i,v in enumerate(m1):
            for j,vv in enumerate(v):
                m3[i][j] = m1[i][j] + m2[i][j]

        return m3

    def sub(self):
        m1 = self.m1
        m2 = self.m2

        if self.sizeMatchValidator(m1, m2) != True:
            return 'matrix size Error'

        m3 = np.zeros((len(m1[0]), len(m1)))

        for i,v in enumerate(m1):
            for j,vv in enumerate(v):
                m3[i][j] = m1[i][j] - m2[i][j]

        return m3

    def sizeMatchValidator(self, m1, m2):
        return len(m1) == len(m2) and len(m1[0]) == len(m2[0])
