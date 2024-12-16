from tabulate import tabulate
def readfiledata(filename):
    nbr_eleves = 0
    dico = {}
    with open(filename, 'r') as file:
        data = [line.strip().split(';') for line in file][1:]
    for row in data:
        nbr_eleves += int(row[12])
        if row[2] not in dico:
            dico[row[2]] = [0, 0, 0, float('inf'), float('-inf')]
        dico[row[2]][0] += int(row[12])
        dico[row[2]][1] += 1
        dico[row[2]][3] = min(dico[row[2]][3], int(row[12]))
        dico[row[2]][4] = max(dico[row[2]][4], int(row[12]))
    for key in dico:
        dico[key][2] = dico[key][0] / dico[key][1]
    total_establishments = sum([values[1] for values in dico.values()])
    avg_students_per_establishment = nbr_eleves / total_establishments
    table = [[key, *values] for key, values in dico.items()]
    headers = ["Accadémie", "Total élèves", "Nombre d'Etablissement", "Moyenne élèves", "Min élèves", "Max élèves"]
    table.append(["Total", nbr_eleves, total_establishments, avg_students_per_establishment, min([values[3] for values in dico.values()]), max([values[4] for values in dico.values()])])
    print(tabulate(table, headers, tablefmt="pretty"))
readfiledata("data.csv")

