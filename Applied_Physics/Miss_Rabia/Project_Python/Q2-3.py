import numpy as np
import math as m 
import matplotlib.pyplot as plt
def dampedOscillation( Xm, origAngFreq, phi, t, b):
    mass=1.0
    displacement=Xm*m.exp((-b*t)/(2*mass))*m.cos(origAngFreq*t+phi)
    if b<2*mass*origAngFreq:
        condition="under damped"
    elif b==2*mass*origAngFreq:
        condition="critical damped"
    else:
        condition="over damped"
    return displacement, condition
Xm=float(input("Enter amplitude 'Xm': "))
origAngFreq = float(input("Enter angular frequency 'w': "))
phi=float(input("Enter Phase constant '\u03C6': "))
t=float(input("Enter time 't': "))
b=float(input("Enter damping coefficient 'b': "))
X,condition=dampedOscillation( Xm, origAngFreq, phi, t, b)
print("displacement =", X, "and the oscillation is", condition)
timeValues=np.linspace(0, 10, 1000)
displacementValues=[dampedOscillation( Xm, origAngFreq, phi, t, b)[0] for t in timeValues]
plt.plot(timeValues,displacementValues,label='Displacement')
plt.xlabel("Time")
plt.ylabel("Displacement")
plt.title("Damped Oscillation")
plt.legend()
plt.grid(True)
plt.show()