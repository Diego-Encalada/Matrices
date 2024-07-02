#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas, columnas;
    int **matriz, **matriz_traspuesta;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Reservar memoria para la matriz
    matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Reservar memoria para la matriz traspuesta
    matriz_traspuesta = (int **)malloc(columnas * sizeof(int *));
    for (int i = 0; i < columnas; i++) {
        matriz_traspuesta[i] = (int *)malloc(filas * sizeof(int));
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

    // Calcular la matriz traspuesta
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_traspuesta[j][i] = matriz[i][j];
        }
    }

    // Imprimir la matriz traspuesta
    printf("Matriz traspuesta:\n");
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            printf("%d ", matriz_traspuesta[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < columnas; i++) {
        free(matriz_traspuesta[i]);
    }
    free(matriz_traspuesta);

    return 0;
}