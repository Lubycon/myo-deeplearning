import logging;


class Activation:
    def __init__(self, value):
        self.value = value

    def step(self):
        return 1 if self.value > 0 else 0
