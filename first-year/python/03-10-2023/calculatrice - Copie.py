premier_nombre = int(input("Quel est votre premier nombre ? "))
deuxieme_nombre = int(input("Quel est votre deuxieme nombre ? "))
operateur = str(input("Quel opérateur voulait vous utiliser ? "))
if operateur == "+":
    print(premier_nombre + deuxieme_nombre)
elif operateur == "-":
    print(premier_nombre - deuxieme_nombre)
elif operateur == "*":
    print(premier_nombre * deuxieme_nombre)
elif operateur == "/":
    print(premier_nombre / deuxieme_nombre)
else:
    print("Cet operation n'est pas possible.")
