#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas, columnas;
    int **matriz;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Reservar memoria para la matriz
    matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Ingresar valores para la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz generada
    printf("Matriz generada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimir valores que no están en las esquinas
    printf("Valores que no están en las esquinas:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (!(i == 0 && j == 0) && // Esquina superior izquierda
                !(i == 0 && j == columnas - 1) && // Esquina superior derecha
                !(i == filas - 1 && j == 0) && // Esquina inferior izquierda
                !(i == filas - 1 && j == columnas - 1)) { // Esquina inferior derecha
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}