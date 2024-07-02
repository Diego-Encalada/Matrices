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

    // Imprimir valores de las esquinas
    printf("Valores de las esquinas:\n");
    printf("%d ", matriz[0][0]); // Esquina superior izquierda
    printf("%d ", matriz[0][columnas - 1]); // Esquina superior derecha
    printf("%d ", matriz[filas - 1][0]); // Esquina inferior izquierda
    printf("%d ", matriz[filas - 1][columnas - 1]); // Esquina inferior derecha
    printf("\n");

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}