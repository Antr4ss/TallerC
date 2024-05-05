#include <stdio.h>
#include <string.h>

void replaceCharacter(char *string, char originalChar, char replacementChar);

int main(void) {

    char auxOption4 [50] ;
    char char1Option4;
    char char2Option4;
    int option;
    do {
        printf("Bienvenido al menu\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
        printf("4. Replace occurrences\n");
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
                printf("Opcion 1\n");
                break;
            case 2:
                printf("Opcion 2\n");

                break;
            case 3:
                printf("Opcion 3\n");
                break;
            case 4:
                printf("Enter the string: ");
                scanf(" %[^\n]", auxOption4);
                printf("Enter the character to be replaced: ");
                scanf(" %c", &char1Option4);
                printf("Enter the new character: ");
                scanf(" %c", &char2Option4);
                replaceCharacter(auxOption4, char1Option4, char2Option4);

                printf("Modified  string:  %s\n", auxOption4);


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

void replaceCharacter(char *string, char originalChar, char replacementChar) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == originalChar) {
            string[i] = replacementChar;
        }
    }
}
