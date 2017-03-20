import os
import sys
import logging

import filter_class

logging.basicConfig(level=logging.DEBUG)

# volt = filter_class.FilterClass('./data/volt.csv')
# volt.averageFilter()

sonar = filter_class.FilterClass('./data/sonar_alt.csv')
sonar.movingAverageFilter(50)
