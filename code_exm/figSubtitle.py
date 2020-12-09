import matplotlib.pyplot as plt 
import numpy as np 
import matplotlib.gridspec as gridspec 
from mpl_toolkits.axes_grid1 import make_axes_locatable 


plt.close('all') 
arr = np.arange(100).reshape((10, 10)) 
fig = plt.figure(figsize =(4, 4)) 
im = plt.imshow(arr, interpolation ="none", cmap ="plasma") 

divider = make_axes_locatable(plt.gca()) 
cax = divider.append_axes("left", "15 %", pad ="30 %") 

plt.colorbar(im, cax = cax) 

fig.suptitle('matplotlib.pyplot.gca() functionExample\n\n', fontweight ="bold") 
plt.show()