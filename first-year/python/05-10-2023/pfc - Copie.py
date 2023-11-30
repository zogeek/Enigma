from random import randint

a = str(input("Que voulais vous jouer Pierre Feuille ou Ciseaux? "))
b = randint(1, 3)
if a == "pierre":
    if b == 1:
        print("Vous avez fait égalité.")
    elif b == 2:
        print("Vous avez perdu.")
    elif b == 3:
        print("Vous avez gagné.")
elif a == "feuille":
    if b == 1:
        print("Vous avez gagné.")
    elif b == 2:
        print("Vous avez fait égalité.")
    elif b == 3:
        print("Vous avez perdu.")
elif a == "Ciseaux":
    if b == 1:
        print("Vous avez perdu.")
    elif b == 2:
        print("Vous avez gagné.")
    elif b == 3:
        print("Vous avez fait égalité.")

else:
    print("Veuillez entrer une valeur valide")
