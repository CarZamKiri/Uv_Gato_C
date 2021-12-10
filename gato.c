#include <stdio.h>

struct datos
{
  int gato[3][3]; //Matriz base del juego
  int turno; //Numero del turno
  int modo;
}dat_juego;

int main(int argc, char const *argv[])
{
  int salida_menu=0, opcion_menu, volver_menu=0;
  printf("¡Bienvenido al juego del Gato!\n");
  printf("Selecciona lo que deseas hacer a continuación\n");
  do
  {
    printf(" 1 - Iniciar Juego\n 2 - Ver Reglas\n 3 - Imprimir (Para jugar en papel)\n 4 - Salir\n");
    scanf("%s", opcion_menu);
    if (opcion_menu >= 1 && opcion_menu <= 4)
    {
      do
      {
        if (opcion_menu == 4)
        {
          volver_menu = 1;
        }
      } while(volver_menu != 1);
    }
    else
    {
      printf("Debes ingresar una opción valida [1-4]\n");
    }
    
  } while(salida_menu!=1);

  return 0;
}
