#include <stdio.h>

struct datos
{
    int gato[3][3]; //Matriz base del juego
    int turno; //Numero del turno
    int modo;
}dat_juego;

int main(int argc, char const *argv[])
{
    char excla=173, oacento=162, inte=168, flecha=175, iacento=161, uacento=163;
    int salida_menu=0, opcion_menu, volver_menu, salida_gen=0;
    printf("%cBienvenido al juego del Gato!\n",excla);
    printf("Selecciona lo que deseas hacer a continuaci%cn:\n", oacento);
    do
    {
        printf(" 1 - Iniciar Juego\n 2 - Ver Reglas\n 3 - Imprimir (Para jugar en papel)\n 4 - Salir\n");
        scanf("%i", &opcion_menu);
        if (opcion_menu >= 1 && opcion_menu <= 3)
        {
            do
            {
                if (opcion_menu = 2)
                {
                    do
                    {
                        printf("Objetivo:    Unir 3 figuras en l%cnea recta (vertical, horizontal o diagonal).\n", iacento);
                        printf("En su turno: El jugador escoge una casilla vac%ca del tablero y coloca su figura en esa casilla.\n", iacento);
                        printf("Gana:        El jugador que logre poner 3 figuras en una l%cnea (vertical, horizontal o diagonal).\n", iacento);
                        printf("EMPATE:      Se ocupan todas las casillas y ning%cn jugador realizo una l%cnea recta.\n", uacento ,iacento);
                        printf("%cPresione 1 para volver al menu\n", flecha);
                        scanf("%i", &volver_menu);
                    } while(volver_menu != 1);
                }
            } while(volver_menu != 1);
        }
        else if (opcion_menu == 4)
        {
            salida_menu=1;
        }
        else
        {
            printf("Debes ingresar una opci%cn valida [1-4]\n\n", oacento);
        }
    } while(salida_menu!=1);

return 0;
}
