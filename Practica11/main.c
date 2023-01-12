#include <stdio.h>
#include <stdio.h>
#include <conio.h>

#define N 8
typedef unsigned uint;
typedef struct HORA {
    unsigned hora,minuto,segundo;
}HORA;

typedef struct COMPLEJO {
    float real,imaginaria;
    HORA  tiempo;
}COMPLEJO;

typedef struct C_LIST {
    unsigned total;
    COMPLEJO  lista[N];
}C_LIST;

void print_HORA(struct HORA );
void scan_HORA(struct HORA *);
void scan_COMP (struct COMPLEJO *);
void print_COMP(struct COMPLEJO);
void print_menu();
void cualquier_tecla(); // espera que se pulse cualquier tecla, sin hacer echo
void inicializar_lista(struct C_LIST *);
void aniadir_COMPLEJO(struct C_LIST *,struct COMPLEJO);
void eliminar_COMPLEJO(struct C_LIST *);
// elimina el ultimo complejo añadido a la lista
void print_lista_COMPLEJOS(struct C_LIST);

int main() {
    C_LIST complejos;
    COMPLEJO complejo;
    short opt;

    inicializar_lista(&complejos);

    do
    {
        system("cls");
        print_menu();
        printf("Seleccione una opcion:");
        scanf("%hd", &opt);
        switch(opt)
        {
            case 1:
                scan_COMP(&complejo);
                aniadir_COMPLEJO(&complejos, complejo);
                cualquier_tecla();
                break;
            case 2:
                eliminar_COMPLEJO(&complejos);
                cualquier_tecla();
                break;
            case 3:
                print_lista_COMPLEJOS(complejos);
                cualquier_tecla();
                break;
        }

    }while(opt);

    return 0;
}

void print_HORA(struct HORA hora)
{
    printf("%u:%u:%u",hora.hora, hora.minuto, hora.segundo);
}

void print_COMP(struct COMPLEJO complejo)
{
    printf("%f%fi",complejo.real, complejo.imaginaria);
    print_HORA(complejo.tiempo);
}

void scan_HORA(struct HORA *hora)
{
    printf("hh:mm:ss?");
    scanf("%u:%u:%u", &hora->hora, &hora->minuto, &hora->segundo);
}

void scan_COMP(struct COMPLEJO *comp)
{
    printf("parte real?");
    scanf("%f",&comp->real);
    printf("\nparte imaginaria?");
    fflush(stdin);
    scanf("%f",&comp->imaginaria);
    printf("\nhora de la posicion?");
    scan_HORA(&(comp->tiempo));

}

void cualquier_tecla()
{
    printf("PULSE CUALQUIER TECLA...");
    getch();
}

void print_menu()
{
    printf("POSICIONES DE UN MOVIL CON COORDENADAS COMPLEJAS\n");
    printf("1.-Agregar un complejo\n");
    printf("2.-Eliminar un numero complejo\n");
    printf("3.-Listar numeros complejos\n");
    printf("0.-Salir\n");
}

void inicializar_lista(struct C_LIST *lista)
{
    lista->total = 0;
}

void aniadir_COMPLEJO(struct C_LIST *lista,struct COMPLEJO comp)
{
    if(lista->total < N)
    {
        lista->lista[lista->total] = comp;
        lista->total++;
    }
}

void eliminar_COMPLEJO(struct C_LIST *lista)
{
    if(lista->total)
        lista->total--;
    else
        printf("La lista ya esta vacia.");
}

void print_lista_COMPLEJOS(struct C_LIST lista)
{
    uint i;
    for(i = 0; i < lista.total; i++)
    {
        print_COMP(lista.lista[i]);
        printf("\n");
    }
}


