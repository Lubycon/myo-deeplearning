import os
import sys
import logging

import emg_class as emg

logging.basicConfig(level=logging.DEBUG)

filterSize = 10

fist = emg.EMGClass('./data/myo/emg-fist.csv')
fist.getMAFilter(filterSize)

spread = emg.EMGClass('./data/myo/emg-spread.csv')
spread.getMAFilter(filterSize)

wavein = emg.EMGClass('./data/myo/emg-wavein.csv')
wavein.getMAFilter(filterSize)

waveout = emg.EMGClass('./data/myo/emg-waveout.csv')
waveout.getMAFilter(filterSize)
