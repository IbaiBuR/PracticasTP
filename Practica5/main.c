#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int potencia(int ,int ); // base, exponente
void print_binario(int ); // printa en binario un int
void pulsar(); // espera a pulsar una tecla
void scan(int*,int*); // scan de base y de exponente límite

int main()
{
    int base, exp,k;
    scan(&base, &exp);

    for(k = 0; k <= exp; k++) {
        printf("Los datos introducidos son: \nBase = %d \nExponente = %d\nDecimal = %d\n", base, k, potencia(base, k));
        print_binario(potencia(base, k));
        pulsar();
    }

    return 0;
}

void scan(int *b, int *e)
{
    do
    {
        printf("Introduzca la base(2-10): ");
        scanf("%d",b);
    }while(*b < 2 || *b > 10);

    do
    {
        printf("Introduzca el exponente(0-10):");
        scanf("%d",e);
    }while(*e < 0 || *e > 10);
}

void pulsar()
{
    printf("PULSE UNA TECLA PARA CONTINUAR...");
    getch();
}

int potencia(int base, int exp)
{
    int i,elevator;

    for(i = 0, elevator = 1; i <= exp; i++)
    {
        if(i == 0)
            elevator = 1;
        else
            elevator *=base;
    }

    return elevator;
}

void print_binario(int n)
{
    int i;

    for(i = 0; n; n/=2,i++)
        printf("bit%d=%d\n",i,n%2);
}