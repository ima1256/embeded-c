#include <stdio.h>
#include <unistd.h>

void printBits(unsigned int x) {

    for (int i = sizeof(x)*8 - 1; i >= 0; i--) {
        char t = ((x >> i) & 1) + '0';
        write(1, &t, 1);
    }

    write(1, "\n", 1);

}

int invert_bit(int x, int n) {
    return  x ^= (1 << n);
}

int alertas(int *sensores, int n, int umbral) {

    if ( n < 1 ) return 0;
    int res = 0;

    //sizeof(sensores[0])*8 - 1 - i)

    for (int i = 0; i < n; i++) {
        if (*sensores > umbral) {
            res |= 1 << i;
        }
        sensores++;
    }

    return res;
}

/*int main() {
    int x = 13; // 1101 en binario
    int n = 2;
    printf("Resultado: %d\n", invert_bit(x, n)); // debería imprimir 9 (1001)
    return 0;
}*/

int main() {

    int sensores[] = {10, 25, 30, 5}; // 4 sensores

    int n = sizeof(sensores) / sizeof(sensores[0]);
    int umbral = 20;
    
    // Sensor 1 y 2 superan 20 → bits 1 y 2 a 1 → 0110 binario = 6 decimal
    printf("Bits de alerta: %d\n", alertas(sensores, n, umbral)); // debería imprimir 6
    return 0;
}