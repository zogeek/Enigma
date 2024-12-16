import matplotlib.pyplot as plt
import numpy as np

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

fig, ax = plt.subplots()
ax.plot(x, y, color='blue', label='Ligne Bleue')
ax.set_title("Graphique")
ax.set_xlabel("X")
ax.set_ylabel("Y")

y_plus_one = [value + 1 for value in y]
ax.plot(y_plus_one, x,linestyle="--", color='red', label='Ligne Rouge')

ax.legend()
plt.show()