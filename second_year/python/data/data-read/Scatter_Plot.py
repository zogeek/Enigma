import matplotlib.pyplot as plt

maths = [70, 85, 60, 90, 55, 75]
physique = [60, 95, 70, 80, 45, 85]
noms = ['Alice', 'Bob', 'Charlie', 'David', 'Eve', 'Frank']
fig, ax = plt.subplots()
ax.scatter(maths, physique, color='blue')
ax.set_title("Notes en maths et en physique")
ax.set_xlabel("Maths")
ax.set_ylabel("Physique")
for i, txt in enumerate(noms):
    ax.annotate(txt, (maths[i], physique[i]))
plt.show()