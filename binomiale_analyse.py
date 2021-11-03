import matplotlib.pyplot as plt
import numpy as np

E, random_E, diff_E = np.loadtxt(fname="data/data_binomiale.csv", delimiter=',', usecols=(0, 1, 2), unpack=True, skiprows=1)
fig, ax = plt.subplots(figsize=(20,5))
im = ax.scatter(E, random_E, c=diff_E,cmap="jet", lw=0)
fig.colorbar(im, ax=ax)
plt.title("Différence entre E et random_E selon n et p")
plt.xlabel("n")
ylabel = plt.ylabel('y')
ylabel.set_rotation(0)
plt.savefig(fname="data/graphique.png")