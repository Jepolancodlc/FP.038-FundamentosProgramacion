//AA3. Tratamiento de secuencias I
//FASE 2

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

// Prototipos de las funciones
void inicializaMenosUno(int n, int arr[]);
void generaCarton(int arr[]);
void imprimeCarton(int arr[]);
int generaNumerosAleatorios(int arr[], int* aleatorio);
void marcaAciertos(int arr[], int* aciertosCarton, int numero);

int main() {
    srand(time(NULL));

    // Inicialización
    inicializaMenosUno(100, carton1);
    inicializaMenosUno(100, carton2);
    inicializaMenosUno(100, numGenerados);

    // Generar cartones
    generaCarton(carton1);
    generaCarton(carton2);

    // Juego principal
    while (aciertosCarton1 < 20 && aciertosCarton2 < 20) {
        int rnd;
        if (generaNumerosAleatorios(numGenerados, &rnd)) {
            system("cls");
            printf("Ha salido el numero: ([%d])\n", rnd);

            // Comprobar y marcar aciertos en los cartones
            marcaAciertos(carton1, &aciertosCarton1, rnd);
            marcaAciertos(carton2, &aciertosCarton2, rnd);

            // Imprimir cartones
            printf("\nMi carton:\n");
            imprimeCarton(carton1);
            printf("\nTu carton:\n");
            imprimeCarton(carton2);

            // Imprimir números generados
            printf("\nNumeros que han salido:\n");
            imprimeCarton(numGenerados);

            Sleep(1000);

            // Verificar ganador
            if (aciertosCarton1 == 20 && aciertosCarton2 == 20) {
                printf("\nEMPATEEEEEEEEEEEEEEEEEEE!\n");
                break;
            }
            if (aciertosCarton1 == 20) {
                printf("\n¡HE GANADO!\n");
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

// Implementación de las funciones
void inicializaMenosUno(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        arr[i] = -1;
    }
}

void generaCarton(int arr[]) {
    for (int i = 0; i < 20; i++) {
        int rnd = rand() % 5 + i * 5;
        arr[rnd] = rnd;
    }
}

void imprimeCarton(int arr[]) {
    printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
    for (int i = 0; i < 100; i++) {
        if (arr[i] == -1) {
            printf("|   .   ");
        }
        else if (arr[i] == 219) {
            printf("|  %c    ", 219);
        }
        else {
            printf("|  %2d   ", arr[i]);
        }
        if ((i + 1) % 10 == 0) {
            printf("|\n");
            printf("+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
        }
    }
}

int generaNumerosAleatorios(int arr[], int* aleatorio) {
    int rnd = rand() % 100;
    if (arr[rnd] == -1) {
        arr[rnd] = rnd;
        *aleatorio = rnd;
        return 1;
    }
    return 0;
}

void marcaAciertos(int arr[], int* aciertosCarton, int numero) {
    if (arr[numero] != -1 && arr[numero] != 219) {
        arr[numero] = 219;
        (*aciertosCarton)++;
    }
}