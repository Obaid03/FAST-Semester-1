# import numpy as np
def Angle(s):
    cosx=s[0]/(np.linalg.norm(s))
    x=np.arccos(cosx)
    anglex=np.degrees(x)
    cosy=s[1]/(np.linalg.norm(s))
    y=np.arccos(cosy)
    angley=np.degrees(y)
    cosz=s[2]/(np.linalg.norm(s))
    z=np.arccos(cosz)
    anglez=np.degrees(z)
    print('The angle of Vector A with X-axis is : ',anglex)
    print('The angle of Vector A with Y-axis is : ',angley)
    print('The angle of Vector A with Z-axis is : ',anglez)
A=[2,-3,5]
Angle(A)