#include <stdio.h>
#define maximo_chars 64


// prototipos
void binario_entera(int, char [maximo_chars]);
// un int se convierte a binario (se almacena en el array)

void binario_fraccionaria(float , char [maximo_chars]);
// un float se convierte a binario (se almacena en el array)

void resetear(char [maximo_chars]);  // se resetea el array

void poner_posicion (char [maximo_chars],int , char );
// se coloca un char en la posicion int del array

int bits_blanco(char [maximo_chars]);
// chars en blanco en el array

void insertar_final(char [maximo_chars],char);
// se inserta un char al final del array, desplazando el resto a la izquierda

void prn_binario(char [maximo_chars]);
// se printa el array con los char del numero binario

void mover_izda(char [maximo_chars]);
// mueve a la izda todos los bits del array

void scan_real(float * );
// scan del número real a convertir

int posicion_punto_decimal (char [maximo_chars]);
// posicion en el array de ‘.’

void notacion_cientifica(char [maximo_chars], int * );
// convierte el binario en notacion cientifica, transmitiendo el exponente

void copiar_mantisa(char [maximo_chars],char [32]);
// copia la mantisa a un array de 32 chars, en las últimos 23 posiciones del array

void copiar_exponente(char [maximo_chars],char r[32]);
// copia el exponente a un array de 32 chars, en las 8 siguientes posiciones a la posicion 0

void colocar_signo(char ,char [32]);
// coloca el signo en un array de 32 chars, en la posicion 0



int main() {
    int a, exponente, l;
    float n, b;
    char binintfrac[maximo_chars], memoria[32];

    resetear(binintfrac);
    scan_real(&n);
    if(n < 0)
    {
        n *= -1;
        colocar_signo('1',memoria);
    }
    else
        colocar_signo('0',memoria);

    a = (int) n;
    b = n - (int)n;

    printf("El numero real en base decimal es: %d\n", a);
    printf("El numero real convertido a binario es: ");
    binario_entera(a, binintfrac);
    insertar_final(binintfrac, '.');
    binario_fraccionaria(b, binintfrac);
    prn_binario(binintfrac);
    for(l = bits_blanco(binintfrac); l; l--)
        insertar_final(binintfrac, ' ');
    copiar_exponente(binintfrac,memoria);
    copiar_mantisa(binintfrac,memoria);

    printf("\nRepresentacion en memoria: ");
    for(l = 0; l < 32; l++)
        printf("%c",memoria[l]);
}
void scan_real(float *n)
{
  printf("Introduzca un numero real:");
  scanf("%f",n);
}
void binario_entera(int a, char array[maximo_chars])
{
    int j;
    for(j= maximo_chars-1 ; a; a/=2, j--)
        array[j]=a%2?'1':'0';
}

void binario_fraccionaria(float b, char array[maximo_chars])
{
    int k;
    for(k = 0; k < 23 && b>0; k++)
    {
        b *= 2;
        insertar_final(array,(int)b>=1?'1':'0');
        b = b -(int)b;
    }
}

void resetear( char array[maximo_chars])
{
    char posres;
    for (posres = 0; posres < maximo_chars; posres++)
        array[posres]=' ';
}

void prn_binario(char array[maximo_chars])
{
    int i;
    for (i = bits_blanco(array); i < maximo_chars; i++)
            printf("%c",array[i]);
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

void poner_posicion( char array[maximo_chars],int a, char c)
{
  array[a] = c;
}

void insertar_final(char array[maximo_chars], char c)
{
  mover_izda(array);
  array[maximo_chars-1] = c;
}

int posicion_punto_decimal(char array[maximo_chars])
{
  int i;
  for(i = 0; i < maximo_chars && array[i] != '.'; i++);
  return i;
}
void mover_izda(char array[maximo_chars])
{
  int i;
  for(i =0 ; i < maximo_chars; i++)
    array[i] = array[i+1];
}

void colocar_signo(char s, char array[32])
{
    array[0] = s;
}

void notacion_cientifica(char array[maximo_chars], int *e)
{
    int i;

    if(array[0] == '1')
    {
        *e = posicion_punto_decimal(array)-1;
        for(i = *e; i; i--)
        {
            array[i+1] = array[i];
            array[i] = '.';
        }
    }

    else
    {
        *e = 0;
        for(;array[0] == '0'; (*e)--)
        {
            insertar_final(array, ' ');
            array[0] = array[1];
            array[1] = '.';
        }

        if(array[0] == ' ')
        {
            *e = -127;
            array[0] = array[2] = '0';
        }

        else if(array[2] == ' ')
            array[2] = '0';
    }

}

void copiar_mantisa(char array[maximo_chars], char m[32])
{
    int i;

    for(i = 9; i < 32 && array[i-7] != ' '; i++)
        m[i] = array[i-7];

    for(; i < 32; i++)
        m[i] = '0';
}

void copiar_exponente(char array[maximo_chars], char m[32])
{
    int i, exponente;
    notacion_cientifica(array, &exponente);
    printf("\nNumero binario en notacion cientifica: ");
    for(i = 0; i < maximo_chars && array[i] != ' '; i++)
        printf("%c",array[i]);
    printf("\nExponente: %d\n",exponente);
    printf("Exponente+127 en binario: ");

    exponente += 127;
    for(i = 8; i; exponente/=2, i--)
        m[i] = (exponente%2)?'1':'0';

    for(i = 1; i <= 8; i++)
        printf("%c",m[i]);
}

