def sapin(n):
    for i in range(1, n + 1):
        print("*" * i)


def max(a, b):
    if a > b:
        return a
    else:
        return b


def estPair(x):
    if x % 2 == 0:
        return True
    else:
        return False


def tousLesPairs(x):
    if x % 2 == 0:
        for i in range(0, x, 2):
            print(i)
    else:
        print("Le nombre n'est pas pair.")


def factorielle(n):
    for i in range(1, n):
        n = n * i
    return n


def estPremier(x):
    for i in range(0):
        if x % i == 0:
            print(x + " est premier.")
        else:
            print(x + "n'est pas premier.")


def necontientqueDesint(l):
    for slt in l:
        if type(slt) != type(1):
            return False
    return True


def maxListe(l):
    if not necontientqueDesint(l):
        return 0
    max = 0
    for slt in l:
        if slt > max:
            max = slt


from random import randint


def lancerDe():
    res = randint(1, 6)
    print(res)


def lancerDeMultiple(n):
    resultat = []
    for i in range(0, n):
        a = randint(1, 6)
        resultat.append(a)
    return resultat


from statistics import mean


def controlDe():
    resultat = []
    for i in range(0, 1000):
        a = randint(1, 6)
        resultat.append(a)
    return mean(resultat)


print(controlDe())


def guessthenumber():
    ianumber = randint(0, 100)
    pnumber = 0
    while ianumber != pnumber:
        pnumber = int(input("Quel numero voulait vous tester?"))
        if ianumber > pnumber:
            print("Le nombre est plus grand")
        elif ianumber < pnumber:
            print("Le nombre est plus petit")
    print("Le numero était", ianumber)


guessthenumber()
