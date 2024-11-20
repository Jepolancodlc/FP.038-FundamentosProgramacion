//AA3. Tratamiento de secuencias I
//FASE 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int carton1[100];
int carton2[100];
int numGenerados[100];
int used[100] = { 0 }; //flag numero usado
int aciertosCarton1 = 0;
int aciertosCarton2 = 0;


int main()
{
    srand(time(NULL));

    for (size_t i = 0; i < 100; i++)
    {
        carton1[i] = -1;
        carton2[i] = -1;
        numGenerados[i] = -1;
    }


    for (size_t i = 0; i < 20; i++)
    {
        int rnd = rand() % 5;
        int rnd2 = rand() % 5;

        //Random incrementa +5 por cada fila 
        rnd += i * 5;
        rnd2 += i * 5;

        carton1[rnd] = rnd;
        carton2[rnd2] = rnd2;
    }


    //Generar numeros aleatorios unicos
    while (aciertosCarton1 < 20 && aciertosCarton2 < 20) {
        int rnd = rand() % 100;

        if (used[rnd] == 0) {
            used[rnd] = 1;
            numGenerados[rnd] = rnd;

            system("cls");
            printf("Ha salido el:([%d])\n", rnd);

            //Comprobar si el numero esta en el carton1 o carton2 y cambiarlo por 219
            if (carton1[rnd] != -1) {
                carton1[rnd] = 219; //Cambiar el numero por el codigo ASCII 219
                aciertosCarton1++;
            }
            if (carton2[rnd] != -1) {
                carton2[rnd] = 219; //Cambiar el numero por el codigo ASCII 219
                aciertosCarton2++;
            }

            printf("\nMi carton:\n");
            printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
            for (size_t i = 0; i < 100; i++) {
                if (carton1[i] == -1) {
                    printf("|   .   "); //default
                }
                else if (carton1[i] == 219) {
                    printf("|  %c    ", 219); //Imprime el numero
                }
                else {
                    printf("|  %2d   ", carton1[i]); //Imprime el numero
                }

                if ((i + 1) % 10 == 0) {
                    printf("|\n");
                    printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
                }
            }

            printf("\nTu carton:\n");
            printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
            for (size_t i = 0; i < 100; i++) {
                if (carton2[i] == -1) {
                    printf("|   .   "); //default
                }
                else if (carton2[i] == 219) {
                    printf("|  %c    ", 219); //Imprime el numero
                }
                else {
                    printf("|  %2d   ", carton2[i]); //Imprime el numero
                }

                if ((i + 1) % 10 == 0) {
                    printf("|\n");
                    printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
                }
            }

            printf("\nNumeros que han salido:\n");
            printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
            for (size_t i = 0; i < 100; i++) {
                if (numGenerados[i] == -1) {
                    printf("|   .   "); //default
                }
                else {
                    printf("|  %2d   ", numGenerados[i]); //Imprime el numero
                }

                if ((i + 1) % 10 == 0) {
                    printf("|\n");
                    printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
                }
            }

            Sleep(10);

            //Comprobacion
            if (aciertosCarton1 == 20 && aciertosCarton2 == 20) {
                printf("\nEMPATEEEEEEEEEEEEEEEEEEE!\n");
                break;
            }
            if (aciertosCarton1 == 20) {
                printf("\nHE GANADO!\n");
                break;
            }
            if (aciertosCarton2 == 20) {
                printf("\nHAS GANADO TU!\n");
                break;
            }
        }
    }
    return 0;
}