#include <stdio.h>
#include <stdlib.h>

void resta_matrices(int **matriz1, int **matriz2, int **matriz_result, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_result[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void imprimir_matriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;
    int **matriz1, **matriz2, **matriz_result;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Reservar memoria para las matrices
    matriz1 = (int **)malloc(filas * sizeof(int *));
    matriz2 = (int **)malloc(filas * sizeof(int *));
    matriz_result = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz1[i] = (int *)malloc(columnas * sizeof(int));
        matriz2[i] = (int *)malloc(columnas * sizeof(int));
        matriz_result[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Ingresar valores para la matriz 1
    printf("Ingrese valores para la matriz 1:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Ingresar valores para la matriz 2
    printf("Ingrese valores para la matriz 2:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Restar matrices
    resta_matrices(matriz1, matriz2, matriz_result, filas, columnas);

    // Imprimir matrices
    printf("Matriz 1:\n");
    imprimir_matriz(matriz1, filas, columnas);
    printf("Matriz 2:\n");
    imprimir_matriz(matriz2, filas, columnas);
    printf("Matriz resultante:\n");
    imprimir_matriz(matriz_result, filas, columnas);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz_result[i]);
    }
    free(matriz1);
    free(matriz2);
    free(matriz_result);

    return 0;
}