#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas, columnas;
    int **matriz;

    printf("Ingrese el número de filas (y columnas): ");
    scanf("%d", &filas);

    columnas = filas; // La matriz simétrica debe ser cuadrada

    // Reservar memoria para la matriz
    matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Ingresar valores para la matriz (solo la parte superior)
    for (int i = 0; i < filas; i++) {
        for (int j = i; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d,%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Copiar la parte superior a la parte inferior para hacerla simétrica
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < i; j++) {
            matriz[i][j] = matriz[j][i];
        }
    }

    // Imprimir la matriz simétrica
    printf("Matriz simétrica:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}