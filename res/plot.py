import numpy as np
import matplotlib.pyplot as plt

# Charger les données du fichier en utilisant numpy.loadtxt et en spécifiant le délimiteur
data = np.loadtxt('res.mat')

# Convertir les données en une matrice 2D
#matrix = np.reshape(data, (374, 374))

# Afficher la matrice en tant qu'image
#plt.imshow(matrix)
plt.imshow(data)
plt.title("Densité nucléaire")
plt.xlabel("z")
plt.ylabel("x")
plt.show()