#include <stdio.h>
#include <stdlib.h>

// Función para multiplicar matrices
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

// Función para calcular la potencia de una matriz
void calcular_potencia(int **matriz, int **matriz_result, int filas, int columnas, int exponente) {
    int **matriz_temp = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz_temp[i] = (int *)malloc(columnas * sizeof(int));
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_temp[i][j] = matriz[i][j];
        }
    }
    for (int i = 1; i < exponente; i++) {
        multiplicar_matrices(matriz_temp, matriz, matriz_result, filas, columnas, columnas);
        for (int j = 0; j < filas; j++) {
            for (int k = 0; k < columnas; k++) {
                matriz_temp[j][k] = matriz_result[j][k];
            }
        }
    }
    for (int i = 0; i < filas; i++) {
        free(matriz_temp[i]);
    }
    free(matriz_temp);
}

// Función para imprimir una matriz
void imprimir_matriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas, exponente;
    int **matriz, **matriz_result;

    printf("Ingrese el número de filas para la matriz: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas para la matriz: ");
    scanf("%d", &columnas);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    // Reservar memoria para las matrices
    matriz = (int **)malloc(filas * sizeof(int *));
    matriz_result = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        matriz_result[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Inicializar matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i + j;
        }
    }

    // Calcular la potencia de la matriz
    calcular_potencia(matriz, matriz_result, filas, columnas, exponente);

    // Imprimir resultados
    printf("Matriz original:\n");
    imprimir_matriz(matriz, filas, columnas);
    printf("Matriz elevada a la potencia %d:\n", exponente);
    imprimir_matriz(matriz_result, filas, columnas);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    for (int i = 0; i < filas; i++) {
        free(matriz_result[i]);
    }
    free(matriz_result);

    return 0;
}