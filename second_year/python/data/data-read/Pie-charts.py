import matplotlib.pyplot as plt

navigateurs = ['Chrome', 'Firefox', 'Edge', 'Safari', 'Autres']
parts = [65, 10, 8, 12, 5]
myexplode = (0.1, 0, 0, 0, 0)

fig, ax = plt.subplots()
ax.pie(parts, labels=navigateurs, autopct='%1.1f%%', startangle=90, explode=myexplode)
ax.set_title("Parts de marché des navigateurs")

plt.show()