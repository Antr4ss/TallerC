#include <stdio.h>

#include <string.h>

int buscarSubcadena(char *string, char *substring, int initialPosition);
void rellenarCadena(char* string, char character, int direction, int numCharacters);


int main(void) {
    int option;
    int initialPosition;
    int result;
    char character;
    int diretcion;
    int numCharacters;


    do {
        printf("Bienvenido al menu\n");
        printf("1.Search substring\n");
        printf("2. Fill string\n");
        printf("3. Opcion 3\n");
        printf("4. Opcion 4\n");
        printf("5. Opcion 5\n");
        printf("6. Opcion 6\n");
        printf("7. Opcion 7\n");
        printf("8. Opcion 8\n");
        printf("9. Opcion 9\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                char string[100];
                char substring[100];
                int noExist=0;

                printf("Enter the string: ");
                scanf(" %[^\n]", string);
                printf("Enter the substring: ");
                scanf("%s", substring);
                printf("Enter the position from where to start the search: ");
                scanf("%d", &initialPosition);
                result = buscarSubcadena(string, substring, initialPosition);
                if (result != -1) {
                    printf("The substring was found at position: %d\n", result);
                } else {
                    printf("Substring position: %d\n", noExist);
                }
            break;

            case 2:
                printf("Enter the string: ");
                scanf(" %[^\n]", string);
                printf("Enter fill character: ");
                scanf(" %c", &character);
                printf("Enter the padding direction (0 for left, 1 for right): ");
                scanf("%d", &diretcion);
                printf("Enter the number of characters to fill: ");
                scanf("%d", &numCharacters);

                rellenarCadena(string, character, diretcion, numCharacters);

                printf("Resulting string: %s\n", string);

            break;

            case 3:
                printf("Opcion 3\n");
                break;

            case 4:
                printf("Opcion 4\n");
                break;
            case 5:
                printf("Opcion 5\n");
                break;
            case 6:
                printf("Opcion 6\n");
                break;
            case 7:
                printf("Opcion 7\n");
                break;
            case 8:
                printf("Opcion 8\n");
                break;
            case 9:
                printf("Opcion 9\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while(option!=0);
    return 0;
}

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


void rellenarCadena(char* string, char character, int direction, int numCharacters) {
    char relleno[numCharacters + 1];
    for(int i = 0; i < numCharacters; i++) {
        relleno[i] = character;
    }
    relleno[numCharacters] = '\0';

    if(direction == 0) {
        // Rellenar a la izquierda
        memmove(&string[numCharacters], string, strlen(string) + 1);
        memcpy(string, relleno, numCharacters);
    } else {
        // Rellenar a la derecha
        strcat(string, relleno);
    }
}





