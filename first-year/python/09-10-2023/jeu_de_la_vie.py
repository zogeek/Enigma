import random
import time
x = 7
y = 7

def creeMap(axe_x,axe_y):
    Map = []
    r = 0
    for i in range(axe_y):
        Map.append([])
        for u in range(axe_x):
            Map[i].append(r)
            r += 1
    return Map

plateau = creeMap(x,y)
print(plateau)

def creeVie(x,y):
    nbVie= []
    for i in range(x*y//3):
        t = random.randint(0,x*y)
        for r in range(x*y):
            if t not in nbVie:
                nbVie.append(t)
                t = 0
            if t+r not in nbVie and t !=0 and t < x*y+1:
                nbVie.append(t+r)
                t= 0
    nbVie.sort()
    return nbVie

nbVie = creeVie(x,y)
print(nbVie)

def affiche(plateau, x,nbVie):
    for i in plateau:
        print(" ")
        print("-"*3*x+"-")
        print("|", end =" ")
        for u in range(x):
            if i[u] in nbVie:
                print("X","|", end ="")
            else:
                print(" ","|", end ="")
    print(" ")
    print("-"*3*x+"-")

def case(plateau,nbVie, i ,u, v,n):
    nbVoisin=0
    if i == max(u) and u == max(plateau):
        if plateau[v-1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
    elif i == max(u) and u == min(plateau):
        if plateau[v+1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
    elif i == min(u) and u == max(plateau):
        if plateau[v-1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
    elif i == min(u) and u == min(plateau):
        if plateau[v+1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
    elif i == max(u):
        if plateau[v-1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
    elif i == min(u):
        if plateau[v-1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
    elif u == min(plateau):
        if plateau[v+1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
    elif u == max(plateau):
        if plateau[v-1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
    else:
        if plateau[v-1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n] in nbVie:
            nbVoisin+=1
        if plateau[v][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v-1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n+1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n-1] in nbVie:
            nbVoisin+=1
        if plateau[v+1][n] in nbVie:
            nbVoisin+=1
    return nbVoisin


def verifie(plateau, nbVie):
    v=0
    nbVoisin =0
    possibleNaissance= []
    condane=[]
    for u in plateau:
        n=0
        for i in u:
            if i in nbVie:
                nbVoisin= case(plateau,nbVie, i ,u,v, n)
                if nbVoisin <2 or nbVoisin > 3:
                    condane.append(plateau[v][n])
            if i not in nbVie:
                nbVoisin = case(plateau,nbVie, i ,u,v, n)
                if nbVoisin >= 3:
                    possibleNaissance.append(plateau[v][n])
            nbVoisin=0
            n+=1
        v+=1
    return possibleNaissance, condane

def NaissanceMort(nbVie, possibleNaissance, condane):
    Vie = []
    for i in nbVie:
        if i not in condane:
            Vie.append(i)
    for u in possibleNaissance:
        if u not in nbVie:
            Vie.append(u)

    Vie.sort()
    return Vie

def nbMax(nbVie,i, nbrMax):
    if len(nbVie) > nbrMax[0]:
        nbrMax[0]= len(nbVie)
        nbrMax[1] = i
        nbrMax[2]= nbVie
        return nbrMax
    return nbrMax


def jeuVie(plateau, x,nbVie):
    nbrMax= [0,-1,[]]
    for i in range(100):
        affiche(plateau, x,nbVie)
        nbrMax = nbMax(nbVie,i, nbrMax)
        possibleNaissance, condane = verifie(plateau, nbVie)
        nbVie = NaissanceMort(nbVie, possibleNaissance, condane)
        time.sleep(1)
    print(nbrMax)
    affiche(plateau, x,nbrMax[2])

jeuVie(plateau, x,nbVie)
