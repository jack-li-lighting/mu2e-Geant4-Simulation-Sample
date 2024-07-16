# -*- coding: utf-8 -*-
"""
Created on Mon Jun 24 01:32:16 2024

@author: jackl
"""

import math
import numpy as np
import matplotlib.pyplot as plt
import os

def RMCgammaEnergyDistri (E_y, E_y_end, C):
    x = E_y/E_y_end
    P_x = C*(1-2*x + 2*math.pow(x,2))*x*math.pow(1-x,2)
    
    return P_x

E_y_hist = np.arange(0, 100, 1)
P_x_hist = np.zeros(len(E_y_hist))

i = 0
for E_y in E_y_hist:
    P_x_hist[i] = RMCgammaEnergyDistri(E_y, 100, 10)
    i += 1

plt.figure()
plt.plot(E_y_hist, P_x_hist)
plt.title("RMC photon energy spectrum")
plt.xlabel("Energy/[MeV]")
plt.ylabel("Weight")
plt.show()

#gammaSpectrum = np.zeros((len(E_y_hist),3))
#for i in np.arange(0, 100, 1):
    #gammaSpectrum[i, 0] = "/gps/hist/point"
    #gammaSpectrum[i, 1] = E_y_hist[i]
    #gammaSpectrum[i, 2] = P_x_hist[i]

with open(os.getcwd() + "\Downloads\mu2p\mac\gammaSpectrum.mac", 'w') as f:
    for i in np.arange(0, 100, 1):
        f.write("/gps/hist/point " + str(E_y_hist[i]) + " " + 
                str(P_x_hist[i]) + "\n")
f.close()
    