#include <stdio.h>

void enteroABinario(int n, char *cadena) {// Convierte un entero a su representación binaria en una cadena de caracteres
    for (int i = 31; i >= 0; i--) { // Recorremos los bits de mayor a menor (31 a 0) y llenamos la cadena con '1' o '0' según corresponda
        *(cadena + (31 - i)) = (n >> i & 1) ? '1' : '0'; // Desplazamos 'n' a la derecha 'i' veces y verificamos el bit menos significativo para determinar si es '1' o '0' y lo almacenamos en la posición correspondiente de la cadena
    }
    *(cadena + 32) = '\0';
}

int main() { 
    int num, unos = 0;
    char bin[33], *p = bin; // 'p' es un apuntador que se usará para recorrer la cadena 'bin' y contar los bits '1', mientras que 'bin' es un arreglo de caracteres que almacenará la representación binaria del número ingresado por el usuario
    
    printf("Ingresa un entero positivo: ");
    scanf("%d", &num);
    enteroABinario(num, bin);
    printf("Binario: %s\n", bin);

    // --- TU CÓDIGO AQUÍ ---
    // Usa 'p' para recorrer 'bin' y contar los '1's
    while (*p != '\0') {
        if (*p == '1') {
            unos++;
        }
        p++;
    }

    printf("Total de bits '1': %d\n", unos);
    return 0;
}

// PREGUNTA: En la función enteroABinario, estamos pasando un int (4 bytes) y un apuntador char *. 
// Si un int ya vive en la memoria como una secuencia de bits, 
// ¿por qué es necesario 'convertirlo' a una cadena de caracteres para contarlos con el apuntador?
// RESPUESTA: Aunque un int vive en la memoria como una secuencia de bits, no es directamente legible o manipulable como una secuencia de caracteres.
// El proceso de convertir el int a una cadena de caracteres (binario) nos permite representar visualmente los bits como '0' y '1', lo que facilita el conteo de los bits '1' utilizando un apuntador char *.
