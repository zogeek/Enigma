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


def changer_etat_true(a, environement):
    """Change le statut d'une case en fonction du type et de la position dans l'environnement (True ou False)."""
    """ Fonction permettant d'échanger les états des cellules du plateau (vide ou pleine)."""
    environement[a] = True
    return environement

def changer_etat_false(a, environement):
    """Change le statut d'une case en fonction du type et de la position dans l'environnement (True ou False)."""
    """ Fonction permettant d'échanger les états des cellules du plateau (vide ou pleine)."""
    environement[a] = False
    return environement


def celules_vivantes(x, environement):
    celules_vivantes = []
    for i in range(0, x):
        a = randint(0, taille_environement(environement))
        if not a in celules_vivantes:
            celules_vivantes.append(a)
            changer_etat_true(a, environement)
    return environement


def cel_7_test(i, environement):
    if i + 7 > taille_environement(environement):
        changer_etat_false(i, environement)
    else:
        if environement[i + 7] == True:
            changer_etat_true(i, environement)
    return environement


def cel_7_if(i, environement):
    if i + 7 > taille_environement(environement):
        changer_etat_false(i, environement)
    elif i + 7 < taille_environement(environement):
        if environement[i + 7] == True:
            if environement[i - 1] == True:
                changer_etat_true(i, environement)
            elif environement[i - 7] == True:
                changer_etat_true(i, environement)
            elif environement[i + 1] == True:
                changer_etat_true(i, environement)
    return environement
def cel_7_test_false(i, environement):
    if i + 7 > taille_environement(environement):
        changer_etat_false(i, environement)
    elif i + 7 < taille_environement(environement):
        if environement[i + 7] == False:
            if environement[i - 1] == False:
                if environement[i + 1] == False:
                    changer_etat_true(i, environement)
                elif environement[i - 7] == False:
                    changer_etat_false(i, environement)
            if environement[i + 1] == False:
                if environement[i - 1] == False:
                    changer_etat_true(i, environement)
                elif environement[i - 7] == False:
                    changer_etat_false(i, environement)
            if environement[i - 7] == False:
                if environement[i - 1] == False:
                    changer_etat_true(i, environement)
                elif environement[i + 1] == False:
                    changer_etat_false(i, environement)
    return environement

def cel_7_if_false(i, environement):
    if i + 7 > taille_environement(environement):
        changer_etat_false(i, environement)
    elif i + 7 < taille_environement(environement):
        if environement[i + 7] == False:
            if environement[i - 1] == False:
                if environement[i +  1] == False:
                    changer_etat_true(i, environement)
                elif environement[i - 7] == False:
                    changer_etat_true(i, environement)
            if environement[i + 1] == False:
                if environement[i - 1] == False:
                    changer_etat_true(i, environement)
                elif environement[i - 7] == False:
                    changer_etat_true(i, environement)
            if environement[i - 7] == False:
                if environement[i - 1] == False:
                    changer_etat_true(i, environement)
                elif environement[i + 1] == False:
                    changer_etat_true(i, environement)
            else:
                changer_etat_false(i, environement)
    return environement


def testcel_vivantes(environement):
    for i in range(0, taille_environement(environement)):
        if environement[i - 1] == True:
            if environement[i + 1] == True:
                changer_etat_true(i, environement)
            elif environement[i - 7] == True:
                changer_etat_true(i, environement)
            else:
                cel_7_test(i, environement)
        elif environement[i - 7] == True:
            if environement[i - 1] == True:
                changer_etat_true(i, environement)
            elif environement[i + 1] == True:
                changer_etat_true(i, environement)
            else:
                cel_7_test(i, environement)
        elif environement[i + 1] == True:
            if environement[i - 1] == True:
                changer_etat_true(i, environement)
            elif environement[i - 7] == True:
                changer_etat_true(i, environement)
            else:
                cel_7_test(i, environement)
        elif i == i :
            cel_7_if(i, environement)
        else:
            changer_etat_false(i , environement)
    return environement



def testcel_mortes(environement):
    for i in range(0, taille_environement(environement)):
        if environement[i - 1] == False:
            if environement[i + 1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i +1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i - 7] == False:
                if environement[i + 1] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif i == i:
                cel_7_test_false(i, environement)
            else:
                changer_etat_false(i, environement)

        if environement[i + 1] == False:
            if environement[i - 1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i - 1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i - 7] == False:
                if environement[i - 1] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif i == i:
                cel_7_test_false(i, environement)
            else:
                changer_etat_false(i, environement)

        if environement[i - 7] == False:
            if environement[i + 1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i +1] == False:
                if environement[i - 7] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif environement[i - 7] == False:
                if environement[i + 1] == False:
                    changer_etat_true(i, environement)
                elif i == i :
                    cel_7_test(i , environement)
            elif i == i:
                cel_7_test_false(i, environement)
            else:
                changer_etat_false(i, environement)

        else:
            cel_7_if_false(i, environement)
            
    return environement


print(testcel_vivantes(celules_vivantes(30, creerenvironement(60))))


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
