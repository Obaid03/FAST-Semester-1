import sympy as sp 
import math as m 
import numpy as np 
import matplotlib.pyplot as plt 
sp.init_printing()
t = sp.symbols('t')
position = 3*sp.sin(t)-2*sp.cos(t)+5*t**3
velocity = sp.diff(position,t)
acceleration = sp.diff(position,t,2)
print("Expression for displacement:", position)
print("Expression for velocity:", velocity)
print("Expression for acceleration:", acceleration)
time_values = np.linspace(0,10,100)
position_values = [position.evalf(subs={t: val}) for val in time_values]
velocity_values = [velocity.evalf(subs={t: val}) for val in time_values]
acceleration_values = [acceleration.evalf(subs={t: val}) for val in time_values]
plt.plot(time_values, position_values, label='Displacement')
plt.plot(time_values, velocity_values, label='Velocity')
plt.plot(time_values, acceleration_values, label='Acceleration')
plt.xlabel("Time (s)")
plt.ylabel("Value")
plt.title("Graph of Displacement, Velocity, and Acceleration vs Time")
plt.legend()
plt.grid(True)
plt.show()