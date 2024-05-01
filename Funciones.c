#include "Funciones.h"
#include <string.h>

int buscarSubcadena(char *string, char *substring, int initialPosition) {
    int i, j;

    for (i = initialPosition; i < strlen(string); i++) {
        if (string[i] == substring[0]) {
            for (j = 1; j < strlen(substring); j++) {
                if (string[i + j] != substring[j]) {
                    break;
                }
            }

            if (j == strlen(substring)) {
                return i;
            }
        }
    }

    return -1;
}
