#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// defines
#define maximo_chars 64
#define B 4
//prototipos de funciones de prácticas anteriores
int bits_blanco(char [maximo_chars]);
// chars en blanco en el array
void insertar_final(char [maximo_chars],char);
// se inserta un char al final del array, desplazando el resto a la izquierda
void mover_izda(char [maximo_chars]);
// mueve a la izda todos los bits del array
void resetear(char [maximo_chars]); // se resetea el array
int posicion_punto_decimal (char [maximo_chars]);
// posicion en el array de ‘.’
// prototipos de las funciones que se deben definir en esta práctica
int longitud(int ); // función recursiva
// longitud(543)=3
float random_real(float*,float*);
// devuelve un número real, calculado aleatoriamente
void real_binario(float ,char[maximo_chars]);
// convierte un numero real en base decimal a base binaria, printando el binario
float numero_real(char b[maximo_chars]);
// devuelve en base 10 el numero real correspondiente a un binario con parte entera y fraccionaria

int main(){
    float n1,exp,random_num;
    char bits_binario[maximo_chars];
    int k;
    resetear(bits_binario);
    srand(time(NULL));
    for(k = 0; k < B; k++)
    {
        random_real(&n1,&exp);
        random_num = (n1 + exp);
        printf("\nrandom real : %f\n",random_num);
        printf("\nnumero real convertido a binario:\n");
        real_binario(n1+exp, bits_binario);
        printf("\n");
        printf("numero real recalculado : %f\n",numero_real(bits_binario));
        resetear(bits_binario);
    }
}
float random_real(float *n1, float *exp)
{
    *n1 = rand()%10001;
    *exp = rand()%1001;
    *exp = *exp/1000;
}
void real_binario(float n, char array[maximo_chars])
{
    int i,j,aux;
    aux = (int)n;
    for(i = maximo_chars-1; aux; aux/=2, i--)
        array[i]=aux%2?'1':'0';
    insertar_final(array,'.');
    for(j = 0; j < 23 && n > 0; j++)
    {
        n = n-(int)n;
        n*= 2;
        insertar_final(array,(int)n>=1?'1':'0');
    }
    for(i = bits_blanco(array); i < maximo_chars; i++)
        printf("%c",array[i]);
}
void insertar_final(char array[maximo_chars], char c)
{
    mover_izda(array);
    array[maximo_chars-1] = c;
}
void mover_izda(char array[maximo_chars])
{
    int i;
    for(i =0 ; i < maximo_chars; i++)
        array[i] = array[i+1];
}
int bits_blanco(char array[maximo_chars])
{
    int i, contador = 0;
    for(i = 0; i < maximo_chars; i++)
    {
        if(array[i] == ' ')
            contador++;
    }
    return contador;
}
void resetear(char array[maximo_chars])
{
    char posres;
    for (posres = 0; posres < maximo_chars; posres++)
        array[posres]=' ';
}
int longitud(int x)
{
    if(x < 10)
        return 1;
    else
        return 1 + longitud(x/10);
}
int posicion_punto_decimal(char array[maximo_chars])
{
    int i;
    for(i = 0; i < maximo_chars; i++)
        if(array[i] == '.')
            return i;
}
float numero_real(char array[maximo_chars]) {
    int i;
    float pdec = 0, pint = 0, longaux;
    for (i = posicion_punto_decimal(array) - 1, longaux = 0; array[i] != ' ' && i >= 0; i--,
            longaux++)
    {
        pint += pow(2, longaux) * (array[i] == '1' ? 1 : 0);
    }
    for (i = posicion_punto_decimal(array) + 1, longaux = -1; i < maximo_chars; i++,
            longaux--) {
        pdec += pow(2, longaux) * (array[i] == '1' ? 1 : 0);
    }
    return pint + pdec;
}