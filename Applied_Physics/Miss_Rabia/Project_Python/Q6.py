import math as m 
import numpy as np 
import matplotlib.pyplot as plt 
mag=10.0
angleA=m.radians(30)
angleB=m.radians(180-105)
Rx=mag*m.cos(angleA)-mag*m.cos(angleB)
Ry=mag*m.sin(angleA)+mag*m.sin(angleB)
R=np.array([Rx,Ry])
print("a)")
print("X-component of R =",Rx)
print("Y-component of R =",Ry)
magR=np.linalg.norm(R)
angleX=m.degrees(m.acos(Rx/magR))
print("b)")
print("Magnitude of R =",magR)
print("c)")
print("Angle R makes with the x-axis : ",angleX,"\u00b0")