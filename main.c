#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id; 
    float temperature;
} Sensor;

void add_one(int *value);

void ask_numbers();

void swap(int *a, int *b);

void set_to_zero(int *p);

int sum_array(int *arr, int length) {

    int total = 0;

    for ( int i = 0; i < length; i++) {
        total += *arr;
        arr++;
    }

    return total;

}

int max_value(int *arr, int length) {

    int max = *arr;
    int i = 0;

    do {
        arr++;
        i++;
        if ( *arr > max) max = *arr;
    } while ( i < length);

    return max;

}

void double_all(int *arr, int length) {

    for ( int i = 0; i < length; i++) {
        *arr *= 2;
        arr++;
    }

}

void set_to_zero(int *p) {

    *p = 0;

}

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}


void ask_numbers() {

    int num_elems = 5;

    int elems[num_elems];

    int max, min, sum = 0;

    for ( int i = 0; i < num_elems; i++) {

        printf("Introduce el digito numero %i\n", i + 1);
        scanf("%d", &elems[i]);

        if ( i == 0) {

            max = elems[i];
            min = elems[i];

        } else {

            if ( elems[i] > max) max = elems[i];

            if ( elems[i] < min) min = elems[i];

        }

        sum += elems[i];

    }

    printf("max = %d, min = %d, sum = %d", max, min, sum);

}

void add_one(int *value) {

    *value += 1;

}

int my_strlen(const char *s) {

    int length = 0;

    while ( *s != '\0') {
        s++;
        length += 1;
    }

    return length;

}

void my_strcopy(char *dest, const char *src) {

    while ( *src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

}

void reverse(int *arr, int length);

void reverse(int *arr, int length) {

    int *first = arr;

    for (int i = 0; i < length - 1; i++) arr++;

    int *last = arr; 

    printf("first = %d, last = %d", *first, *last);

}

int main() {

    int num = 5, a = 0, b = 1;

    add_one(&num);

    printf("%d\n", num);

    swap(&a, &b);

    set_to_zero(&num);

    int array[3] = { 2, 3, 4};

    int total = sum_array(array, 3); 
    int max = max_value(array, 3);

    double_all(array, 3);

    printf("a = %d, b = %d, num = %d, total = %d, max = %d \n array * 2 = ", a, b, num, total, max);

    for ( int i = 0; i < 3; i++) {
        printf("%d ", array[i]);
    }

    printf("\n Longitud: ");

    int length = my_strlen("hola adios ");

    printf("%d \n", length);

    char *copy = malloc(100);

    my_strcopy(copy, "hola buenos dias");

    printf("%s", copy);

    free(copy);

    reverse(array, 3);

    return 0;
}
