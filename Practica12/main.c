#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 512
unsigned num_palabras(FILE *); //devuelve el numero de palabras que hay en el fichero
void print_max_line(FILE *); //imprime por pantalla la linea mayor
void quitar_chars(FILE *, char*, char*); //guarda en otro fichero de texto las lineas del primero que no contengan la cadena de caracteres pasada
int main()
{
    FILE *f_in;
    char cad[15];
    if(!(f_in=fopen("texto1.txt","r")))
    {
        printf("No se ha podido acceder al fichero de forma correcta.");
        return 1;
    }
    printf("El numero de palabras leidas es : %u\n",num_palabras(f_in));
    rewind(f_in);
    print_max_line(f_in);
    printf("\nIntroduzca la cadena de caracteres a eliminar del fichero (max. 14): ");
    gets(cad);
    rewind(f_in);
    quitar_chars(f_in,"salida.txt",cad);
    fclose(f_in);
    return 0;
}
unsigned num_palabras(FILE *f_in)
{
    unsigned cont = 0;
    char linea[MAX_LINES];
    while(fscanf(f_in,"%s",linea) == 1)
        cont++;
    return cont;
}
void print_max_line(FILE *f_in)
{
    char lineas[MAX_LINES],lineamax[MAX_LINES];
    int max = 0,longitud;
    while(fgets(lineas,MAX_LINES,f_in))
    {
        longitud = strlen(lineas);
        if(longitud > max)
        {
            max = longitud;
            strcpy(lineamax,lineas);
        }
    }
    printf("\nLa linea mas larga es: \n %s",lineamax);
}
void quitar_chars(FILE *f_in, char *nomfich, char *cad)
{
    FILE *f_out;
    char lineas[MAX_LINES];
    int i;
    if(!(f_out = fopen(nomfich,"w")))
        printf("No se ha podido acceder al fichero de forma correcta.");
    while(fgets(lineas,MAX_LINES,f_in))
    {
        for(i = 0; lineas[i]; )
        {
            if(strchr(cad,lineas[i]))
                strcpy(lineas+i,lineas+i+1);
            else
                i++;
        }
        fwrite(lineas,sizeof(char),i,f_out);
    }
    fclose(f_out);
}
