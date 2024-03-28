#!/usr/bin/python3
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

fig, ax = plt.subplots()
x = np.arange(0.0, 1.0, 0.01)
y = 4/(1+x*x)
ax.plot(x,y)

N = 10
step = 1/N
for i in range(N):
    cx = i*step
    cy = 0
    height = 4/(1 + cx ** 2)
    ax.add_patch(
         patches.Rectangle(
            (cx, cy),
            step,
            height,
            edgecolor = 'blue',
            facecolor = 'white',
            hatch='/',
            fill=True
         ) )

# patterns = ['/', '\\', '|', '-', '+', 'x', 'o', 'O', '.', '*']
# N = len(patterns)
# step = 1/N
# for i, pattern in enumerate(patterns):
#     cx = i*step 
#     cy = 0
#     height = 4/(1 + cx ** 2)
#     ax.bar(cx+ 0.5 * step, height, width=  step, hatch = pattern, edgecolor = 'blue', facecolor = 'white')


plt.show()

