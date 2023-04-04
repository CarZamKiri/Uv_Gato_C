#include <stdio.h>

int menu_principal (int opcion);

int main(int argc, char **argv)
{

   return 0; 
}

int menu_principal (int opcion)
{
    printf("-------Selecciona una opcion de Estructura de Datos-------\n");
    printf("1)Pilas\n2)Listas\n3)Cola\n4)Lista Doblemente Ligada\n5)Cola Doblemente Ligada\n6)Lista Circular\n7)Cola Circular\n8)Lista Doblemente Ligada Circular\n9)Cola Doblemente Ligada Circular\n10)Salir\n");
    scanf("%d", &opcion);
    do
    {
        if (opcion < 1 || opcion >10)
        {
            printf("Ingresa una opcion valida");
        }
        else
        {
            switch (opcion)
            {
                case 1: printf("Menu de Pilas");         
                case 2: printf("Menu de Listas");
                case 3: printf("Menu de Cola");
                case 4: printf("Menu de Lista Doblemente Ligada");
                case 5: printf("Menu de Cola Doblemente Ligada");
                case 6: printf("Menu de Lista Circular");
                case 7: printf("Menu de Cola Circular");
                case 8: printf("Menu de Lista Doblemente Ligada Circular");
                case 9: printf("Menu de Cola Doblemente Ligada Circular");
                case 10: return 0;
            } 
        } 
    } while (opcion < 1 || opcion > 10);
    return 0;
}