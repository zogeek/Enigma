import pandas as pd

df = pd.read_csv('data.csv', sep=';')
num_rows = df.shape[0]
num_cols = df.shape[1]

print(f"Number of rows: {num_rows}, Number of columns: {num_cols}")
print(f"Nombre d'école: {df['Numéro de l\'école'].nunique()}")
print(f"Moyenne d'éleves ULIS: {df['Nombre d\'élèves en ULIS'].mean()}")
print(f"Moyenne d'élèves en CP hors ULIS: {df['Nombre d\'élèves en CP hors ULIS'].mean()}")
print(f"Moyenne d'élèves en CE1 hors ULIS: {df['Nombre d\'élèves en CE1 hors ULIS'].mean()}")
print(f"Moyenne d'élèves en CE2 hors ULIS: {df['Nombre d\'élèves en CE2 hors ULIS'].mean()}")
print(f"Moyenne d'élèves en CM1 hors ULIS: {df['Nombre d\'élèves en CM1 hors ULIS'].mean()}")
print(f"Moyenne d'élèves en CM2 hors ULIS: {df['Nombre d\'élèves en CM2 hors ULIS'].mean()}")

print(f"Nombre moyen d'eleves en CP par académie: {df.groupby('Académie')['Nombre d\'élèves en CP hors ULIS'].mean()}")