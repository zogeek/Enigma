import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('data.csv', sep=';')
fig, ax = plt.subplots()
temp = df.loc[df['Numéro de l\'école'] == '0030701W']
temp = temp.sort_values(by='Rentrée scolaire')
ax.plot(temp['Rentrée scolaire'], temp['Nombre d\'élèves en CP hors ULIS'], color='blue')
ax.plot(temp['Rentrée scolaire'], temp['Nombre d\'élèves en CE1 hors ULIS'], color='red')
ax.plot(temp['Rentrée scolaire'], temp['Nombre d\'élèves en CE2 hors ULIS'], color='green')

ax.set(xlabel='Année scolaire', ylabel='Nombre d\'élèves', title='Nombre d\'élèves en CP, CE1 et CE2 à l\'école 0030701W')
ax.grid()
plt.legend(['CP', 'CE1', 'CE2'])
plt.show()