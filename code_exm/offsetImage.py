from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox

import matplotlib.pyplot as plt
import matplotlib.image as mpimg

fig, ax = plt.subplots()

ax.set_xlim(0, 1)
ax.set_ylim(0, 1)

img = mpimg.imread('visualizer/img/ant.png')

imagebox = OffsetImage(img, zoom=0.02)

ab = AnnotationBbox(imagebox, (0.4, 0.6))

ax.add_artist(ab)

plt.grid()
plt.draw()
plt.show()
#/home/arrmani88/L