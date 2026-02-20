#include <stdio.h>

void invertirCadena(char *inicio) {
    char *fin = inicio;
    char aux;

    // 1. Mover 'fin' al último carácter antes del '\0'
    while (*fin != '\0') {
        fin++;
    }
    fin--; 

    // 2. Intercambio de valores
    while (inicio < fin) {
        // --- TU CÓDIGO AQUÍ ---
        // Implementa el intercambio usando la variable 'aux'
        // Desplaza los apuntadores adecuadamente
        aux = *inicio; // Guardar el valor en 'aux'
        *inicio = *fin; // Asignar el valor de 'fin' a 'inicio'
        *fin = aux; // Asignar el valor guardado en 'aux' a 'fin'
        inicio++; // Mover 'inicio' hacia adelante              
        fin--; // Mover 'fin' hacia atrás
    }
}

int main() {
    char palabra[] = "APUNTADORES";
    printf("Original: %s\n", palabra);
    invertirCadena(palabra);
    printf("Invertida: %s\n", palabra);
    return 0;
}

//Durante el ciclo de intercambio (swap), la condición de parada es while (inicio < fin). 
//Explica detalladamente qué es lo que se está comparando físicamente en esa instrucción (¿valores o direcciones?) 
// y qué sucedería si la condición fuera while (*inicio != *fin).
// RESPUESTA: En la condición while (inicio < fin), se están comparando las direcciones de memoria a las que apuntan los punteros 'inicio' y 'fin'.
// Esto significa que el ciclo continuará ejecutándose mientras la dirección a la que apunta 'inicio' sea menor que la dirección a la que apunta 'fin'.
// Si la condición fuera while (*inicio != *fin), se estarían comparando los valores almacenados en las direcciones a las que apuntan 'inicio' y 'fin'.
// En este caso, el ciclo continuaría ejecutándose mientras los caracteres en esas posiciones sean diferentes, lo que podría llevar a un comportamiento incorrecto, ya que el objetivo es invertir la cadena, no comparar los caracteres.
