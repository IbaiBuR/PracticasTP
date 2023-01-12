#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FILAS 20
#define COLS 11

typedef unsigned uint;
typedef unsigned short ushort;

void rellenar_mat (char [FILAS][COLS]); // se rellena la matriz de matriculas validas
ushort posicion_eldest(char [FILAS][COLS]); // devuelve la posicion de la matriz donde se encuentra la matricula mas antigua
void imprimir (char [FILAS][COLS]); // imprime la matriz, una matricula por linea

int main() {
    char matriculas[FILAS][COLS];
    srand(time(NULL));

    rellenar_mat(matriculas);
    printf("Imprimos las matriculas generadas:\n");
    imprimir(matriculas);
    printf("La fila con la matricula mas antigua es la %hu", posicion_eldest(matriculas));
    return 0;
}

void rellenar_mat(char mat[FILAS][COLS])
{
    uint i,j;

    for(i = 0, j = 0; i < FILAS; i++)
        mat[i][j] = 'E';
    for(i = 0, j = 1; i < FILAS; i++)
        mat[i][j] = '-';
    for(j = 2; j < 6; j++)
        for(i = 0; i < FILAS; i++)
            mat[i][j] = '0' +rand()%9;
    for(i =0, j = 6; i < FILAS; i++)
        mat[i][j]='-';
    for(j = 7; j < 10; j++)
        for(i = 0; i < FILAS; i++)
            mat[i][j]= 'A'+rand()%26;

    for(i = 0, j = COLS-1; i < FILAS; i++)
        mat[i][j] = '\0';
}

void imprimir(char mat[FILAS][COLS])
{
    uint i,j;

    for(i = 0; i < FILAS; i++)
    {
        if(i < 10)
            printf("%d.  ",i);
        else
            printf("%d. ",i);
        puts(mat[i]);
    }
}

ushort posicion_eldest(char mat[FILAS][COLS])
{

    int i,lastpos = 0;
    for(i = 0; i < FILAS; i++)
    {
        if(strcmp(&mat[lastpos][7],&mat[i][7]) > 0)
            lastpos = i;
        else
        {
            if(strcmp(&mat[lastpos][7],&mat[i][7]) == 0)
            {
                if(strncmp(&mat[lastpos][2],&mat[i][2],4) > 0)
                    lastpos = i;
            }
        }
    }
    return lastpos;

}

