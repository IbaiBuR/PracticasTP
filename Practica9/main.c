#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 25

void rellenar (char *);
void eliminar (char *, char *);
int pos_car_fin (char *, char);


int main() {
    char cad1[N],cad2[N],cad3[N],c;
    srand(time(NULL));

    printf("Generamos las cadenas de caracteres:\n");
    rellenar(cad1);
    rellenar(cad2);
    printf("\nEliminamos los caracteres de cad1 que estan en cad2;\n");
    eliminar(cad1,cad2);
    printf("\nGeneramos una tercera cadena de caracteres:\n");
    rellenar(cad3);
    printf("\nIntroduzca el caracter que quiere localizar el cad3: ");
    fflush(stdin);
    scanf("%c",&c);
    if (pos_car_fin(cad3, c) == -1)
        printf("\nEl caracter que ha seleccionado no se encuentra en la cadena.");
    else
        printf("\nEl caracter seleccionado se encuentra en la posicion %d empezando por el final.", pos_car_fin(cad3, c));


    return 0;
}

void rellenar(char *cad)
{
    unsigned longitud = rand()%24,i;

    for(i = 0; i < longitud; i++)
    {
        short control = rand()%3;

        if(!control)
            cad[i] = 'A' + rand()%26;
        if(control == 1)
            cad[i] = 'a' + rand()%26;
        if(control == 2)
            cad[i] = '0' + rand()%9;
    }

    cad[i] = '\0';
    puts(cad);
}

void eliminar(char *cad1, char *cad2)
{
    unsigned i;

    for(i = 0;cad1[i];)
    {
        if (strchr(cad2, cad1[i]))
            strcpy(cad1 + i, cad1 + i + 1);
        else
            i++;
    }

    puts(cad1);
}

int pos_car_fin(char *cad, char c)
{
    int i,pos;
    for(i = strlen(cad)-1,pos = 0; i ;) {
        if(cad[i] != c)
        {
            i--;
            pos++;
        }
        else{
            if(cad[i] == c)
                return pos;
        }
    }
    return -1;
}
