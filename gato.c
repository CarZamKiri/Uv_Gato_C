#include <stdio.h>
#include <time.h>

void jugador();
void computadora();
int ganador();
void casillas();
void gatotxt();
void limpieza();

struct datos
{
    char gato[3][3]; //Matriz base del juego
    int turno; //Numero del turno
}dat_juego;

int main(int argc, char const *argv[])
{
    char excla=173, oacento=162, inte=168, flecha=175, iacento=161, uacento=163, control;
    int salida_menu=0, opcion_menu, volver_menu, salida_gen=0, modo_de_juego;
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
                if (opcion_menu == 1)
                {
                    do
                    {
                        salida_gen = 0;
                        printf("Seleccione modo de juego: \n 1 - Jugador vs Jugador\n 2 - Jugador vs Maquina\n 3 - Regresar a menu\n");
                        scanf("%i", &modo_de_juego);
                        if (modo_de_juego == 1)
                        {
                            printf("%cJugador vs Jugador\n", flecha);
                            do
                            {
                                printf("%cQue desea hacer a continuacion?\n",inte);
                                printf("1 - Volver a jugar\n2 - Volver al menu\n");
                                scanf("%i", &salida_gen);
                                if (salida_gen == 2)
                                {
                                    volver_menu = 1;
                                }
                                else
                                {
                                    printf("Selecciona una opcion valida [1-2]\n");
                                }
                            } while (volver_menu != 1);
                        }
                        else if (modo_de_juego == 2)
                        {
                            printf("%cJugador vs Maquina\n", flecha);
                            do
                            {   
                                int inicia = 0; // Para decidir quien inicia turno
                                printf("%cQuien inicia?\n1 - Jugador\n2 - Maquina\n", inte);
                                scanf("%i", &inicia);
                                if (inicia==1)
                                {
                                    do
                                    {
                                        printf("%cQue desea hacer a continuacion?/n",inte);
                                        printf("1 - Volver a jugar\n2 - Volver al menu");
                                        scanf("%i", &salida_gen);
                                    } while (salida_gen != 2);
                                    volver_menu = 1;
                                }
                                else if (inicia==2)
                                {
                                     do
                                    {
                                        printf("%cQue desea hacer a continuacion?/n",inte);
                                        printf("1 - Volver a jugar\n2 - Volver al menu");
                                        scanf("%i", &salida_gen);
                                    } while (salida_gen != 2);
                                    volver_menu = 1;
                                }
                                else
                                {
                                    printf("Ingresa una opcion valida[1-2]\n");
                                }
                            } while (volver_menu != 1);
                            
                        }
                        else if (modo_de_juego == 3)
                        {
                            volver_menu = 1;
                        }
                        else if (modo_de_juego <1 || modo_de_juego>3)
                        {
                            printf("Ingresa una opcion valida[1-3]\n");
                        }
                    } while (volver_menu!= 1);    
                }
                
                else if (opcion_menu == 2)
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
                else if(opcion_menu == 3)
                {
                    gatotxt();
                    volver_menu = 1;
                }
            } while(volver_menu != 1);
        }    
        else if(opcion_menu == 4)
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

void casillas()
{
    for (int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            printf("| %c", dat_juego.gato[i][j]);   
            
        }
        printf("|");
        printf("\n-------");
        printf("\n");   
    }
}

void gatotxt()
{
    FILE *fichero = fopen("gato.txt","wt");
    if(fichero == NULL) 
    {
		printf("El fichero no se ha podido abrir, no existe.");
	} 
    else 
    {
        printf("El fichero existe y esta en la direccion: %p\n",fichero);
    }
    int i=0,j=0;
    char matriz[21][21]=
    { 
		"      [0]  [1]  [2]  ",
		"[0] ||   ||   ||   ||",
		"    -----------------",
		"[1] ||   ||   ||   ||",
		"    -----------------",
		"[2] ||   ||   ||   ||",
	};
    for(i=0;i<21;i++){
		for(j=0;j<21;j++){	
            
			fputc(matriz[i][j],fichero); //Se imprime la matriz en el txt
		}
		fputs("\n", fichero); //Saltos correspondientes en txt 
	}
	
	fclose(fichero); //Cierre de fichero para liberar memoria
}

int ganador()
{
    if (dat_juego.gato[0][0] == "X" && dat_juego.gato[1][0] == "X" && dat_juego.gato[2][0] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[0][0] == "X" && dat_juego.gato[0][1] == "X" && dat_juego.gato[0][2] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[1][0] == "X" && dat_juego.gato[1][1] == "X" && dat_juego.gato[1][2] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[2][0] == "X" && dat_juego.gato[2][1] == "X" && dat_juego.gato[2][2] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[0][1] == "X" && dat_juego.gato[1][1] == "X" && dat_juego.gato[2][1] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[0][2] == "X" && dat_juego.gato[1][2] == "X" && dat_juego.gato[2][2] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[0][0] == "X" && dat_juego.gato[1][1] == "X" && dat_juego.gato[2][2] == "X")
    {
        return 1;
    }
    else if (dat_juego.gato[0][2] == "X" && dat_juego.gato[1][1] == "X" && dat_juego.gato[2][0] == "X")
    {
        return 1; 
    }
    //Termina Verificacion de x
    if (dat_juego.gato[0][0] == "O" && dat_juego.gato[1][0] == "O" && dat_juego.gato[2][0] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[0][0] == "O" && dat_juego.gato[0][1] == "O" && dat_juego.gato[0][2] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[1][0] == "O" && dat_juego.gato[1][1] == "O" && dat_juego.gato[1][2] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[2][0] == "O" && dat_juego.gato[2][1] == "O" && dat_juego.gato[2][2] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[0][1] == "O" && dat_juego.gato[1][1] == "O" && dat_juego.gato[2][1] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[0][2] == "O" && dat_juego.gato[1][2] == "O" && dat_juego.gato[2][2] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[0][0] == "O" && dat_juego.gato[1][1] == "O" && dat_juego.gato[2][2] == "O")
    {
        return 0;
    }
    else if (dat_juego.gato[0][2] == "O" && dat_juego.gato[1][1] == "O" && dat_juego.gato[2][0] == "O")
    {
        return 0;
    }
    //Termina Verificacion de Y
    else
    {
        return 2; //Da empate
    }
}

void limpieza()
{
    char nulo=00;
    int i=0, j=0;
    for (int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            dat_juego.gato[i][j] = nulo;
        }
    }
}
