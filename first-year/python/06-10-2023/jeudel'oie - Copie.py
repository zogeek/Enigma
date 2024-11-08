from random import randint
from PIL import Image

joueur1 = 0
joueur2 = 0
nb_colonne = 10
nb_ligne = 10
nb_case = nb_ligne*nb_colonne
def plateau():
    n=0
    while n < nb_colonne:
        n=n+1
        if n == 1:
            print("",nb_colonne*"__ ")
        print ("|", end="")
        print(nb_colonne*"__|")
        print
    

while joueur1 < nb_case  and joueur2 < nb_case:
    j1move = randint(1, 6)
    joueur1 = joueur1 + j1move
    j2move = randint(1, 6)
    joueur2 = joueur2 + j2move
    if joueur1 >= nb_case:
        print("Le joueur 1 a gagné")
    elif joueur2 >= nb_case:
        print("Le joueur 2 a gagné")
    plateau()
