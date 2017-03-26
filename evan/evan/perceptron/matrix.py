import numpy as np

class MatrixClass:
    def __init__(self, m1, m2):
        self.m1 = m1
        self.m2 = m2

    def dot(self):
        m1 = self.m1
        m2 = self.m2

        m1Size = self.sizeCal(m1)
        m2Size = self.sizeCal(m2)

        if self.sizeMatchValidator(m1, m2, 'dot') != True:
            return 'Matrix size Error'

        m3 = np.zeros((m1Size['row'], m2Size['col']))

        for i in range(m1Size['row']):
            for j in range(m2Size['col']):
                result = 0

                for k in range(m2Size['row']):
                    result += m1[i][k] * m2[k][j]

                m3[i][j] = result

        return m3


    def add(self):
        m1 = self.m1
        m2 = self.m2

        if self.sizeMatchValidator(m1, m2, 'add') != True:
            return 'Matrix size Error'

        size = self.sizeCal(m1)
        m3 = np.zeros((size['row'], size['col']))

        for i,v in enumerate(m1):
            for j,vv in enumerate(v):
                m3[i][j] = m1[i][j] + m2[i][j]

        return m3

    def sub(self):
        m1 = self.m1
        m2 = self.m2

        if self.sizeMatchValidator(m1, m2, 'sub') != True:
            return 'Matrix size Error'

        size = self.sizeCal(m1)
        m3 = np.zeros((size['row'], size['col']))

        for i,v in enumerate(m1):
            for j,vv in enumerate(v):
                m3[i][j] = m1[i][j] - m2[i][j]

        return m3

    def sizeMatchValidator(self, m1, m2, kind):
        size1 = self.sizeCal(m1)
        size2 = self.sizeCal(m2)

        if kind == 'add' or kind == 'sub':
            return size1['row'] == size2['row'] and size1['col'] == size2['col']
        elif kind == 'dot':
            return size1['row'] == size2['col']



    def sizeCal(self, m):
        return {
            'row': len(m),
            'col': len(m[0])
        }
