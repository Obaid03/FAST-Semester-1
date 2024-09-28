import math as m 
import numpy as np 
def degrees(angle_rad):
    return angle_rad*180/m.pi
r1x=50*(m.cos(30))+50*(m.cos(195))+50*(m.cos(315))
r1y=50*(m.sin(30))+50*(m.sin(195))+50*(m.sin(315))
magr1=m.sqrt(pow(r1x,2)+pow(r1y,2))
thetar1=m.atan2(r1y,r1x)
print("i)")
print("magnitude and angle of vector a + b + c is", magr1,",",degrees(thetar1),"\u00b0")
r2x = 50*(m.cos(30))-50*(m.cos(195))+50*(m.cos(315))
r2y=50*(m.sin(30))-50*(m.sin(195))+50*(m.sin(315))
magr2=m.sqrt(pow(r2x,2)+pow(r2y,2))
thetar2=m.atan2(r2y,r2x)
print("ii)")
print("magnitude and angle of vector a - b + c is", magr2,",",degrees(thetar2),"\u00b0")
dx=50*(m.cos(30))+50*(m.cos(195))-50*(m.cos(315))
dy=50*(m.sin(30))+50*(m.sin(195))-50*(m.sin(315))
magd=m.sqrt(pow(dx,2)+pow(dy,2))
thetad=m.atan2(dy,dx)
print("iii)")
print("magnitude and angle of vector d is", magd,",",degrees(thetad),"\u00b0")