#include <stdio.h>

int menu_principal ();
int menu_secundario();
void crear_archivo_binario(char *nombre_archivo);

int main(int argc, char **argv)
{
    menu_principal();
    return 0; 
}

int menu_principal ()
{
    int opcion = 0;
    printf("-------Selecciona una Estructura de Datos-------\n");
    do
    {
    printf("1)Pilas\n2)Listas\n3)Cola\n4)Lista Doblemente Ligada\n5)Cola Doblemente Ligada\n6)Lista Circular\n7)Cola Circular\n8)Lista Doblemente Ligada Circular\n9)Cola Doblemente Ligada Circular\n10)Salir\n");
    scanf("%d", &opcion);
    
        if (opcion < 1 || opcion >10)
        {
            printf("Ingresa una opcion valida");
        }
        else
        {
            switch (opcion)
            {
                case 1: 
                    printf("Menu de Pilas\n");
                    menu_secundario();
                    break;   
                case 2: 
                    printf("Menu de Listas\n");
                    menu_secundario();
                    break;
                case 3: 
                    printf("Menu de Cola\n");
                    menu_secundario();
                    break;
                case 4: 
                    printf("Menu de Lista Doblemente Ligada\n");
                    menu_secundario();
                    break;
                case 5: 
                    printf("Menu de Cola Doblemente Ligada\n");
                    menu_secundario();
                    break;
                case 6: 
                    printf("Menu de Lista Circular\n");
                    menu_secundario();
                    break;
                case 7: 
                    printf("Menu de Cola Circular\n");
                    menu_secundario();
                    break;
                case 8: 
                    printf("Menu de Lista Doblemente Ligada Circular\n");
                    menu_secundario();
                    break;
                case 9: 
                    printf("Menu de Cola Doblemente Ligada Circular\n");
                    menu_secundario();
                    break;
                case 10: 
                    return 0;
                default:
                    break;
            } 
        } 
    } while (opcion < 1 || opcion > 10);
    return 0;
}

int menu_secundario()
{
    int opc = 0;
    printf("-------Selecciona una opcion de Estructura de Datos-------\n");
    do
    {
    printf("1)Insertar\n2)Borrar\n3)Buscar\n4)Ordenar\n5)Regresar");
    scanf("%d", &opc);
    
        if (opc < 1 || opc  > 5)
        {
            printf("Ingresa una opcion valida");
        }
        else
        {
            switch (opc)
            {
            case 1:
                printf("----Insertando----\n");
                break;
            
            case 2:
                printf("----Borrando----\n");
                break;

            case 3:
                printf("----Buscando----\n");
                break;

            case 4:
                printf("----Ordenando----\n");
                break;

            case 5:
                menu_principal();
                break;

            default:
                break;
            }
        }
    } while (opc < 1 || opc > 5);
    return 0;
}

void crear_archivo_binario(char *nombre_archivo) {
    FILE *archivo;
    archivo = fopen(nombre_archivo, "wb"); // Abrimos el archivo en modo de escritura binaria
    
    if (archivo == NULL) {
        printf("No se pudo crear el archivo\n");
        return;
    }
    
    // Aquí puedes agregar la lógica para escribir los datos en el archivo
    
    fclose(archivo); // Cerramos el archivo
}
