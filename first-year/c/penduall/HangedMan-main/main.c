#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *f_word = fopen("word.txt", "r");
    char word[20];
    int i = 0;
    if (f_word == NULL)
    {
        printf("Error : file do not be found.\n");
        exit(1);
    }
    
    while (fgets(word, 20, f_word) !=  NULL)
    {
        i++;
        printf("%s", word);
    }

    printf("\n%d", i);

    fclose(f_word);
    return 0;
}



// 1) creer une fonction qui determine la taille en int du fichier. note perso:(EOF = end of file).

// 2) prendre le retour de la fonction qui determine la taille du fichier afin d'avoir un nombre max (ex : 1 - 100).

// 3) creer une fonction qui rands dans le fichier et qui sort un mot qui seras utiliser pour le "mot secret".

// 4) prendre ce mot et le changer en string (strcopy (exemple)).

// 5) creer une fonction qui determine la taille du tableau de bool (int) dynamiquement par rapport a la string (mot secret). (si str taille 5, doit créer un tableau qui pourras stocker les bool de la taille du str). malloc(my_strlen() * size_of(int)) (un truc comme ça).

/* créer un tableau 2d pour pouvoir stock toute les string de mon fichier et ensuite les faires rand dans le tableau pour determiner 
 le mot secret. (utilisation de double pointers) et de la fonction malloc(taille * sizeof(type)) */