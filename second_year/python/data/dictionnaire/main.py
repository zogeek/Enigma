data = {"Ville": ["Lille", "Paris", "Marseille"],"Ecole": ["ENIGMA", "EPITECH", "Sciences PO"],"Effectif": [3, 9, 200]}
def print_list_items(data):
    col_width = max(len(str(word)) for row in data.values() for word in row) + 2
    print(end=" | ")
    for key in data:
        print(f"{key:^{col_width}}", end=" | ")
    print()
    for i in range(len(data["Ville"])):
        print(end=" | ")
        for key in data:
            print(f"{str(data[key][i]):^{col_width}}", end=" | ")
        print()
print_list_items(data)