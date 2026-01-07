#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_bits(uint32_t x, int n_bits) {

    for(int i = sizeof(x)*8 - 1; i >= (32 - n_bits); i--) {
        printf("%d", (x >> i) & 1);

    }
    printf("\n");

}

uint32_t* monitor_sensores(const int *sensores, int n, int umbral, int *num_bloques) {

    if (!sensores || n < 1 || !num_bloques) return NULL;
    
    *num_bloques = (n + 31) / 32;

    uint32_t *response = calloc(*num_bloques, sizeof(uint32_t));

    if (!response) return NULL;

    int block_pos = 0;

    for (int i = 0; i < n; i++) {

        block_pos = i / 32;

        int bit = i % 32;

        if (sensores[i] > umbral) {
            response[block_pos] |= 1u << ( 31 - bit);
        }
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
        print_bits(alertas[i], n);
    }

    for (int i = 0; i < n; i++) {
        int block = i / 32;
        int bit = i % 32; 

        if ((alertas[block]) & (1u << (31 - bit))) {
           printf("Sensor %d activo con valor %d\n", i, sensores[i]); 
        }
     
    }
    
    free(alertas);
    return 0;
}
