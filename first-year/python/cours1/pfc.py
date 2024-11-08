pmove = print(str(input("Que voulais vous jouer Pierre Feuille ou Ciseaux? ")))
iamove = random.randrange(3)
if pmove == "pierre":
    if iamove == 1:
        print("Vous avez fait égalité.")
    elif iamove == 2:
        print("Vous avez perdu.")
    elif iamove == 3:
        print("Vous avez gagné.")
elif pmove == "feuille":
    if iamove == 1:
        print("Vous avez gagné.")
    elif iamove == 2:
        print("Vous avez fait égalité.")
    elif iamove == 3:
        print("Vous avez perdu.")
if pmove == "Ciseaux":
    if iamove == 1:
        print("Vous avez perdu.")
    elif iamove == 2:
        print("Vous avez gagné.")
    elif iamove == 3:
        print("Vous avez fait égalité.")
else:
    print("Cet action n'est pas possible.")
