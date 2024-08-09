# Code by GVV Sharma
# September 12, 2023
# Revised July 21, 2024
# Released under GNU GPL
# Median Length of Triangle

import sys                                          # for path to external scripts
sys.path.insert(0, '/sdcard/github/matgeo/codes/CoordGeo')        # path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

# local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

# if using termux
import subprocess
import shlex
# end if

# Given vertices of the triangle
A = np.array([2, -5]).reshape(-1,1) 
B = np.array([-2, 9]).reshape(-1,1)  
C = np.array([5, 3]).reshape(-1,1)  

# Midpoint of BC
M = (B + C) / 2

# Length of median AM
median_length = LA.norm(A - M)

# Print the length of the median
print("Length of the median AM:", median_length)

# Generate lines for plotting
x_AM = line_gen(A, M)
x_AB = line_gen(A, B)
x_BC = line_gen(B, C)
x_CA = line_gen(C, A)

# Plotting the triangle and the median
plt.plot(x_AM[0,:], x_AM[1,:], label='$AM$')
plt.plot(x_AB[0,:], x_AB[1,:], label='$AB$')
plt.plot(x_BC[0,:], x_BC[1,:], label='$BC$')
plt.plot(x_CA[0,:], x_CA[1,:], label='$CA$')

# Labeling the coordinates
tri_coords = np.block([[A, B, C, M]])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A', 'B', 'C', 'M']
for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

# Use set_position
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

# if using termux
plt.savefig('/sdcard/fig.pdf')
subprocess.run(shlex.split("termux-open /sdcard/fig.pdf"))
#else
#plt.show()

