#include <stdio.h>
#include <stdlib.h>
#define maximo_chars 64

void binario_entera(int, char [maximo_chars]);// un int se convierte a binario (se almacena en el array)
void binario_fraccionaria(float , char [maximo_chars]);// un float se convierte a binario (se almacena en el array)
void resetear(char [maximo_chars]); // se resetea el array
void poner_posicion (char [maximo_chars],int , char );// se coloca un char en la posicion int del array
int bits_blanco(char [maximo_chars]);// chars en blanco en el array
void insertar_final(char [maximo_chars],char);// se inserta un char al final del array, desplazando el resto a la izquierda
void prn_binario(char [maximo_chars]);// se printa el array con los char del numero binario

int main() {
    int entera;
    float n;
    char bits[maximo_chars];

    resetear(bits);
    printf("Introduzca la parte entera del numero real:");
    scanf("%d",&entera);
    printf("Introduzca la parte decimal del numero real:");
    fflush(stdin);
    scanf("%f",&n);
    binario_entera(entera, bits);
    binario_fraccionaria(n, bits);
    printf("\nEl numero real convertido a binario es:\n");
    prn_binario(bits);



    return 0;
}

void insertar_final(char array[maximo_chars], char c)
{
    int i;

    for(i = 0; i < maximo_chars; i++)
        array[i] = array[i+1];

    array[maximo_chars-1] = c;
}
void binario_entera(int n, char array[maximo_chars])
{
    int i;
    for(i = maximo_chars-1; n; n/=2,i--)
        array[i] = n%2?'1':'0';
    insertar_final(array,'.');
}

void binario_fraccionaria(float n, char array[maximo_chars])
{
    int i;
    for(i = 0; i < 23 && n; i++)
    {
        n = n-(int)n;
        n*=2;
        insertar_final(array,(int)n>=1?'1':'0');
    }
}

void resetear(char array[maximo_chars])
{
    int i;
    for(i = 0; i < maximo_chars; i++)
        array[i] = ' ';
}

void poner_posicion(char array[maximo_chars],int n, char c)
{
    array[n] = c;
}

int bits_blanco(char array[maximo_chars])
{
    int i,cont = 0;

    for(i = 0; i < maximo_chars; i++)
        if(array[i] == ' ')
            cont++;

    return cont;
}

void prn_binario(char array[maximo_chars])
{
    int i;
    for(i = bits_blanco(array); i < maximo_chars; i++)
        printf("%c",array[i]);
}