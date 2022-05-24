"""
import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([1, 8])
ypoints = np.array([3, 10])

plt.plot(xpoints, ypoints)
plt.show()
"""
"""
import matplotlib.pyplot as plt
import numpy as np
  
x = []
y = []
with open("Babbling_data_11min_12V_052322_907.txt", "r") as f:
    data = f.readlines()
    #open('Babbling_data_11min_12V_052322_907.txt', 'r')
#for line in open('Babbling_data_11min_12V_052322_907.txt', 'r'):
    #lines = [i for i in line.split()]
    x.append([1,len(data)])

    #y = np.array([0, len(data.readlines()),1])
    #y = np.arange(len(data.readlines()))
    #y.append(int(lines[1]))
for line in data:
    lines = [i for i in line.split()]
    y.append(lines[0])

plt.title("Students Marks")
plt.xlabel('Roll Number')
plt.ylabel('Marks')
plt.yticks(y)
plt.plot(x, y, marker = 'o', c = 'g')


plt.show()
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
plt.style.use('ggplot')

# Using numpy we can use the function loadtxt to load your CSV file.
# We ignore the first line with the column names and use ',' as a delimiter.
data_12v = np.loadtxt('Babbling_data_11min_12V_052322_907.csv', delimiter=',', skiprows=30)
data_6V = np.loadtxt('Babbling_data_11min_6V_052322_934.csv', delimiter=',', skiprows=30)


# You can access the columns directly, but let us just define them for clarity.
# This uses array slicing/indexing to cut the correct columns into variables.
q1_left_12V = data_12v[:,7]
q2_left_12V = data_12v[:,9]
q1_right_12V = data_12v[:,6]
q2_right_12V = data_12v[:,8]

q1_left_6V = data_6V[:,7]
q2_left_6V = data_6V[:,9]
q1_right_6V = data_6V[:,6]
q2_right_6V = data_6V[:,8]

# With matplotlib we define a new subplot with a certain size (10x10)
#fig, ax = plt.subplots(2,figsize=(10,10))
fig, ax = plt.subplots(2,2)

ax[0,0].plot(q1_left_12V, q2_left_12V, 'o',  markersize=1, label='Ground speed [m/s]')
ax[0,0].set_ylim([-900, 1000])
ax[0,0].set_xlim([-500,500])

ax[0,1].plot(q1_right_12V, q2_right_12V, 'o', markersize=1, label='Voltage [V]')
ax[0,1].set_ylim([-900, 1000])
ax[0,1].set_xlim([-500,500])

ax[1,0].plot(q1_left_6V, q2_left_6V, 'o',  markersize=1,  label='Ground speed [m/s]')
ax[1,0].set_ylim([-900, 1000])
ax[1,0].set_xlim([-500,500])

ax[1,1].plot(q1_right_6V, q2_right_6V, 'o',  markersize=1,  label='Voltage [V]')
ax[1,1].set_ylim([-900, 1000])
ax[1,1].set_xlim([-500,500])

plt.show()

#plt.show()

# Show the legend
plt.legend()