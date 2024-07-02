#include <stdio.h>
#include <stdlib.h>

void multiplicar_matrices(int **matriz1, int **matriz2, int **matriz_result, int filas1, int columnas1, int columnas2) {
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            matriz_result[i][j] = 0;
            for (int k = 0; k < columnas1; k++) {
                matriz_result[i][j] += matriz1[i][k] * matriz2[k][j];
            }
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
    int filas1, columnas1, filas2, columnas2;
    int **matriz1, **matriz2, **matriz_result;

    printf("Ingrese el número de filas para la matriz 1: ");
    scanf("%d", &filas1);

    printf("Ingrese el número de columnas para la matriz 1: ");
    scanf("%d", &columnas1);

    printf("Ingrese el número de filas para la matriz 2: ");
    scanf("%d", &filas2);

    printf("Ingrese el número de columnas para la matriz 2: ");
    scanf("%d", &columnas2);

    // Verificar si se puede realizar la multiplicación
    if (columnas1 != filas2) {
        printf("No se puede realizar la multiplicación. El número de columnas de la matriz 1 debe ser igual al número de filas de la matriz 2.\n");
        return 1;
    }

    // Reservar memoria para las matrices
    matriz1 = (int **)malloc(filas1 * sizeof(int *));
    matriz2 = (int **)malloc(filas2 * sizeof(int *));
    matriz_result = (int **)malloc(filas1 * sizeof(int *));
    for (int i = 0; i < filas1; i++) {
        matriz1[i] = (int *)malloc(columnas1 * sizeof(int));
    }
    for (int i = 0; i < filas2; i++) {
        matriz2[i] = (int *)malloc(columnas2 * sizeof(int));
    }
    for (int i = 0; i < filas1; i++) {
        matriz_result[i] = (int *)malloc(columnas2 * sizeof(int));
    }

    // Ingresar valores para la matriz 1
    printf("Ingrese valores para la matriz 1:\n");
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas1; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Ingresar valores para la matriz 2
    printf("Ingrese valores para la matriz 2:\n");
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Multiplicar matrices
    multiplicar_matrices(matriz1, matriz2, matriz_result, filas1, columnas1, columnas2);

    // Imprimir matrices
    printf("Matriz 1:\n");
    imprimir_matriz(matriz1, filas1, columnas1);
    printf("Matriz 2:\n");
    imprimir_matriz(matriz2, filas2, columnas2);
    printf("Matriz resultante:\n");
    imprimir_matriz(matriz_result, filas1, columnas2);

    // Liberar memoria
    for (int i = 0; i < filas1; i++) {
        free(matriz1[i]);
        free(matriz_result[i]);
    }
    for (int i = 0; i < filas2; i++) {
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);
    free(matriz_result);

    return 0;
}