#include <stdio.h>
#include <stdlib.h>

int* monitor_sensores(int *sensores, int n, int umbral, int *num_bloques) {
    
    if ( n < 1 ) return NULL;
    
    *num_bloques = (n + 31) / 32;

    int *response = calloc(*num_bloques, sizeof(int));

    int block_pos = 0;

    for (int i = 0; i < n; i++) {

        block_pos = i / 32;

        if (*sensores > umbral) {
            response[block_pos] |= 1 << (i % 32);
        }

        sensores++;
    }

    return response;
}

int main() {
    int sensores[] = {10, 25, 30, 5, 50, 60, 15, 0}; // 8 sensores
    int n = sizeof(sensores) / sizeof(sensores[0]);
    int umbral = 20;
    
    int num_bloques;
    int *alertas = monitor_sensores(sensores, n, umbral, &num_bloques);
    
    for (int i = 0; i < num_bloques; i++) {
        printf("Bloque %d: %d\n", i, alertas[i]);
    }
    
    free(alertas);
    return 0;
}
