#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
int exercise_1();
int exercise_2();

int main()
{
    exercise_2(); // Call the function to execute the exercise
    return 0;

}

// Función que lee una línea completa desde la entrada estándar y la retorna como cadena dinámica
char* readline() {
    size_t alloc_length = 1024; // Tamaño inicial del buffer
    size_t data_length = 0;    // Cantidad de datos leídos
    char* data = malloc(alloc_length); // Reserva memoria inicial

    // Bucle para leer la entrada en fragmentos si es necesario
    while (true) {
        char* cursor = data + data_length; // Apunta al final de los datos leídos
        char* line = fgets(cursor, alloc_length - data_length, stdin); // Lee desde stdin

        if (!line) { break; } // Si no se leyó nada, termina el bucle

        data_length += strlen(cursor); // Actualiza la cantidad de datos leídos

        // Si se leyó toda la línea (no se llenó el buffer o se encontró '\n'), termina el bucle
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        // Si el buffer se llenó y no se encontró '\n', duplica el tamaño del buffer
        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length); // Reserva más memoria

        if (!data) { break; } // Si falla la reserva, termina el bucle

        alloc_length = new_length; // Actualiza el tamaño del buffer
    }

    // Si el último carácter es un salto de línea, lo reemplaza por el terminador nulo
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    // Ajusta el tamaño del buffer al tamaño exacto de los datos leídos
    data = realloc(data, data_length);

    return data; // Retorna la cadena leída
}

int exercise_1(){

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    // Write Your Code Here
    // printf("numero %d", n);
    if (n==1){
        printf("one");
        return 0;
    }
    else if ((n==2)) {
        printf("two");
        return 0;
    }    
    else if ((n==3)) {
        printf("three");
        return 0;
    }   
    else if ((n==4)) {
        printf("four");
        return 0;
    }   
    else if ((n==5)) {
        printf("five");
        return 0;
    }   
    else if ((n==6)) {
        printf("six");
        return 0;
    }   
    else if ((n==7)) {
        printf("seven");
        return 0;
    }   
    else if ((n==8)) {
        printf("eight");
        return 0;
    } 
    else if ((n==9)) {
        printf("nine");
        return 0;
    }   
    else{   
        printf("Greater than 9");
        return 0;
    }
}

int exercise_2() {
    const char *str = "12345abc"; char *endptr; errno = 0; // Reset errno before calling strtol
    long int value = strtol(str, &endptr, 10);
    if (errno == ERANGE) {
        printf("Value out of range!\n");
    } else if (endptr == str) {
        printf("No digits were found!\n");
    } else {
        printf("Converted value: %ld\n", value);
        printf("Remaining string: %s\n", endptr);
    }
return 0;
}
