import os
import sys
import logging

import emg_class as emg

logging.basicConfig(level=logging.DEBUG)

filterSize = 20

# DATA LINK START
dataRoot = '/Users/evan/Dev/myo/study/data/myo/'
dataDic = {
    'fist': dataRoot + 'sEMGsamples(fist)-1490341225.csv',
    'spread': dataRoot + 'sEMGsamples(spread)-1490341323.csv',
    'wavein': dataRoot + 'sEMGsamples(wavein)-1490341362.csv',
    'waveout': dataRoot + 'sEMGsamples(waveout)-1490341675.csv'
}
# DATA LINK END

fist = emg.EMGClass(dataDic['fist'])
fist.getMAFilter(filterSize)

spread = emg.EMGClass(dataDic['spread'])
spread.getMAFilter(filterSize)

wavein = emg.EMGClass(dataDic['wavein'])
wavein.getMAFilter(filterSize)

waveout = emg.EMGClass(dataDic['waveout'])
waveout.getMAFilter(filterSize)
