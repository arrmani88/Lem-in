import numpy as np
import matplotlib.pyplot as plt
N = 4
y = np.zeros(N)
x = np.linspace(0, 10, N, endpoint=True)
print(x)
plt.plot(x, y, 'o')
plt.ylim([-0.5, 1])

plt.show()