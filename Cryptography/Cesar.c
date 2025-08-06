#include <stdio.h>      // Para printf
#include <string.h>     // Para manipulación de cadenas


void Additive_Cipher(char *mensaje, int desplazamiento); // Prototipo de la función para cifrar usando el cifrado César
void Decode_Additive_Cipher(char *mensaje, int desplazamiento); // Prototipo de la función para descifrar usando el cifrado César

void Multiplicative_Cipher(char *mensaje, int factor); // Prototipo de la función para cifrar usando el cifrado César
void Decode_Multiplicative_Cipher(char *mensaje, int factor); // Prototipo de la función para descifrar usando el cifrado César
int mod_inverse(int a, int m); // Prototipo de la función para calcular el inverso multiplicativo

int main() {
    char texto[] = "HolaMundo"; // Mensaje original a cifrar
    int offset = 3;              // Desplazamiento para el cifrado César
    // Additive_Cipher(texto, offset);  // Llama a la función para cifrar el mensaje
    Multiplicative_Cipher(texto, offset); // Llama a la función para cifrar usando el cifrado multiplicativo
    printf("Cifrado: %s\n", texto); // Muestra el mensaje cifrado
    // Decode_Additive_Cipher(texto, offset); // Llama a la función para descifrar el mensaje
    Decode_Multiplicative_Cipher(texto, offset); // Llama a la función para descifrar usando el cifrado multiplicativo
    printf("Descifrado: %s\n", texto); // Muestra el mensaje descifrado
    return 0;
}

// Función que cifra un mensaje usando el cifrado César
// 'mensaje' es la cadena a cifrar
// 'desplazamiento' es el número de posiciones a mover cada letra
void Additive_Cipher(char *mensaje, int desplazamiento) {
    // Recorre cada carácter de la cadena
    for (int i = 0; mensaje[i] != '\0'; i++) {
        char c = mensaje[i]; // Obtiene el carácter actual
        // Si el carácter es una letra mayúscula
        if (c >= 'A' && c <= 'Z')
            // Aplica el desplazamiento y mantiene el rango de 'A' a 'Z'
            mensaje[i] = 'A' + (c - 'A' + desplazamiento) % 26;
        // Si el carácter es una letra minúscula
        else if (c >= 'a' && c <= 'z')
            // Aplica el desplazamiento y mantiene el rango de 'a' a 'z'
            mensaje[i] = 'a' + (c - 'a' + desplazamiento) % 26;
        // Si no es letra, lo deja igual
    }
}

void Decode_Additive_Cipher(char *mensaje, int desplazamiento) {
    // Recorre cada carácter de la cadena
    for (int i = 0; mensaje[i] != '\0'; i++) {
        char c = mensaje[i]; // Obtiene el carácter actual
        // Si el carácter es una letra mayúscula
        if (c >= 'A' && c <= 'Z')
            // Aplica el desplazamiento y mantiene el rango de 'A' a 'Z'
            mensaje[i] = 'A' + (c - 'A' - desplazamiento) % 26;
        // Si el carácter es una letra minúscula
        else if (c >= 'a' && c <= 'z')
            // Aplica el desplazamiento y mantiene el rango de 'a' a 'z'
            mensaje[i] = 'a' + (c - 'a' - desplazamiento) % 26;
        // Si no es letra, lo deja igual
    }
}

void Multiplicative_Cipher(char *mensaje, int factor) {
    // Recorre cada carácter de la cadena
    for (int i = 0; mensaje[i] != '\0'; i++) {
        char c = mensaje[i]; // Obtiene el carácter actual
        // Si el carácter es una letra mayúscula
        if (c >= 'A' && c <= 'Z')
            // Aplica el desplazamiento y mantiene el rango de 'A' a 'Z'
            mensaje[i] = 'A' + ((c - 'A') * factor) % 26;
        // Si el carácter es una letra minúscula
        else if (c >= 'a' && c <= 'z')
            // Aplica el desplazamiento y mantiene el rango de 'a' a 'z'
            mensaje[i] = 'a' + ((c - 'a') * factor) % 26;
        // Si no es letra, lo deja igual
    }
}

void Decode_Multiplicative_Cipher(char *mensaje, int factor) {
    int inv = mod_inverse(factor, 26); // Calcula el inverso multiplicativo
    if (inv == -1) {
        printf("No existe inverso multiplicativo para %d modulo 26\n", factor);
        return;
    }
    // Recorre cada carácter de la cadena
    for (int i = 0; mensaje[i] != '\0'; i++) {
        char c = mensaje[i]; // Obtiene el carácter actual
        // Si el carácter es una letra mayúscula
        if (c >= 'A' && c <= 'Z')
            mensaje[i] = 'A' + ((c - 'A') * inv) % 26;
        // Si el carácter es una letra minúscula
        else if (c >= 'a' && c <= 'z')
            mensaje[i] = 'a' + ((c - 'a') * inv) % 26;
        // Si no es letra, lo deja igual
    }
}

// Calcula el inverso multiplicativo de 'a' módulo 'm'
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        printf("Trying x = %d %d\n", x, ((a * x) % m)); // Debugging line to see the value of x
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No existe inverso
}
