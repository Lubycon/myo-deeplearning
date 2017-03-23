import os
import sys
import logging

import emg_class as emg

logging.basicConfig(level=logging.DEBUG)

fist = emg.EMGClass('./data/myo/emg-fist.csv')
fist.getMAFilter(20)

spread = emg.EMGClass('./data/myo/emg-spread.csv')
spread.getMAFilter(20)

wavein = emg.EMGClass('./data/myo/emg-wavein.csv')
wavein.getMAFilter(20)

waveout = emg.EMGClass('./data/myo/emg-waveout.csv')
waveout.getMAFilter(20)
