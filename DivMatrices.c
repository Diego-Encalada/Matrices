#include <stdio.h>
#include <stdlib.h>

// Función para calcular la determinante de una matriz
int calcular_determinante(int **matriz, int n) {
    int i, j, det = 0;
    int **matriz_temp;

    if (n == 1) {
        return matriz[0][0];
    }

    // Crear una matriz temporal para calcular la determinante
    matriz_temp = (int **)malloc((n - 1) * sizeof(int *));
    for (i = 0; i < n - 1; i++) {
        matriz_temp[i] = (int *)malloc((n - 1) * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        // Crear una matriz temporal para calcular el cofactor
        for (j = 0; j < n; j++) {
            int k;
            for (k = 0; k < n; k++) {
                if (k!= j) {
                    matriz_temp[j - 1][k - 1] = matriz[j][k];
                }
            }
        }

        det += (i % 2 == 0? 1 : -1) * matriz[0][i] * calcular_determinante(matriz_temp, n - 1);
    }

    // Liberar memoria
    for (i = 0; i < n - 1; i++) {
        free(matriz_temp[i]);
    }
    free(matriz_temp);

    return det;
}