from random import randint


def creerenvironement(x):
    """Fonction qui crée l'environnement de jeu.
    Entrées : x, nombre de cases sur une des axes."""
    environement = []
    for i in range(0, x):
        environement.append(False)
    return environement


def taille_environement(environement):
    a = len(environement) - 1
    return a


def changer_etat(x, environement):
    """Change le statut d'une case en fonction du type et de la position dans l'environnement (True ou False)."""
    """ Fonction permettant d'échanger les états des cellules du plateau (vide ou pleine)."""
    environement[x] = True


def celules_vivantes(x, environement):
    celules_vivantes = []
    for i in range(0, x):
        a = randint(0, taille_environement(environement))
        if not a in celules_vivantes:
            celules_vivantes.append(a)
            changer_etat(a, environement)
    return environement


print(celules_vivantes(4, creerenvironement(15)))


def testcel(environement):
    for i in range(0, taille_environement(environement)):

print(testcel(celules_vivantes(5, creerenvironement(10))))


"""
cellules_vivantes = int(input("Combien voulez vous de celliles vivantes ? "))
celulles_mortes = 100 - cellules_vivantes
nombre_cellules = cellules_vivantes + celulles_mortes -1
tableau_vivant = []




for i in range(0, cellules_vivantes):
    a = randint(0, nombre_cellules)
    if not a in tableau_vivant:
        tableau_vivant.append(a)

for elt in tableau_vivant:
    print(str(elt), ", ")
print()



print(tableau_vivant)
"""
