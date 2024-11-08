def sapin(n):
    for i in range(1, n+1):
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


print(tousLesPairs(8))


def factorielle(n):
    for i in range(1, n):
        n = n*i
    return n


print(factorielle(5))


def estPremier(x):
    for i in range():
        if x % i == 0:
            print(x+" est premier.")
        else:
            print(x + "n'est pas premier.")
