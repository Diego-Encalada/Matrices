#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas, columnas;
    int **matriz, **matriz_inversa;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Reservar memoria para la matriz
    matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Reservar memoria para la matriz inversa
    matriz_inversa = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz_inversa[i] = (int *)malloc(columnas * sizeof(int));
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

    // Calcular la matriz inversa
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_inversa[j][i] = matriz[i][j];
        }
    }

    // Imprimir la matriz inversa
    printf("Matriz inversa:\n");
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            printf("%d ", matriz_inversa[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < columnas; i++) {
        free(matriz_inversa[i]);
    }
    free(matriz_inversa);

    return 0;
}