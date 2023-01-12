#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int base, exp,i,j,dec,dec2;
    char resp;

    do
    {
        do
        {
           printf("Introduzca la base(2-10):");
           scanf("%d",&base);
        }while(base < 2 || base > 10);

        do
        {
            printf("Introduzca el exponente(0-10):");
            fflush(stdin);
            scanf("%d",&exp);
        }while(exp < 0 || exp > 10);

        printf("Desea modificar los datos?(s/n)");
        fflush(stdin);
        scanf("%c",&resp);
    }while(resp == 's' || resp == 'S');

    for(i = 0, dec = 1; i <=exp; i++)
    {
        if(i == 0)
            dec = 1;
        else
            dec *= base;
        printf("base = %d\nexponente = %d\nnumero decimal = %d\n",base,i,dec);
        dec2 = dec;
        for(j = 0; dec2; dec2/=2,j++)
            printf("bit%d=%d\n",j,(dec2%2));
        printf("PULSE UNA TECLA PARA CONTINUAR...");
        getch();
    }

    return 0;
}
