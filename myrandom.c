#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void initialize_seed() {
    srand((unsigned)(time(NULL) ^ (uintptr_t)&initialize_seed));
}

// Genera un float entre min y max
float randFloat(float min, float max) {
    // Quemamos los primeros 5 valores para evitar sesgo
    for (int i = 0; i < 5; i++) rand();

    float scale = rand() / (float) RAND_MAX;
    return min + scale * (max - min);
}

int main() {
    initialize_seed();

    for (int i = 0; i < 10; i++)
        printf("%f\n", randFloat(0, 10));

    return 0;
}
