import matplotlib.pyplot as plt

pays = ['USA', 'Chine', 'Inde', 'Russie', 'Japon']
population = [328, 1439, 1380, 146, 126]

fig, ax = plt.subplots()
ax.bar(pays[0], population[0], color='blue')
ax.bar(pays[1], population[1], color='red')
ax.bar(pays[2], population[2], color='green')
ax.bar(pays[3], population[3], color='yellow')
ax.bar(pays[4], population[4], color='purple')
ax.set_title("Population par pays")
ax.set_xlabel("Pays")
ax.set_ylabel("Population (en millions)")

plt.show()