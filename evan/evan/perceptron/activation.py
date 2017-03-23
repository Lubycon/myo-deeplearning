import logging;


class Activation:
    def __init__(self, x1, x2, theta):
        self.x1 = x1
        self.x2 = x2
        self.theta = theta

    def step(self):
        result = self.x1 + self.x2 > self.theta
        return 1 if result else 0
