import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
df = pd.read_csv('data.csv', sep=';')
fig, ax = plt.subplots()
grouped = df.groupby('Rentrée scolaire')['Nombre d\'élèves en CP hors ULIS'].mean()
ax.plot(grouped.index, grouped.values, color='blue', linestyle='dashed')
lille = df.loc[df['Académie'] == 'LILLE']
grouped_lille = lille.groupby('Rentrée scolaire')['Nombre d\'élèves en CP hors ULIS'].mean()
ax.plot(grouped_lille.index, grouped_lille.values, color='red', linestyle='dashed')
ax.set(xlabel='Année scolaire', ylabel='Nombre d\'élèves', title='Nombre d\'élèves en CP hors ULIS')
ax.grid()
plt.legend(['France', 'Lille'])
plt.show()