#include <stdio.h>
#include <string.h>

void replaceCharacter(char *string, char originalChar, char replacementChar);
int startsWith(const char *baseString, const char *checkString);
void removeDuplicates(char *str);
int searchString(char *string, char *substring, int initialPosition);
void fillString(char* string, char character, int direction, int numCharacters);
char* extractSubstring(char* string, int posInicial, int posFinal);

int main(void) {

    char auxOption4 [50];
    char auxOption5 [50];
    char auxOption6 [50];
    char verify [50];
    char char1Option4;
    char char2Option4;
    int result;
    int option;
    int initialPosition, finalPosition;
    char character;
    int diretcion;
    int numCharacters;
    char* subsString;

    do {
        printf("Bienvenido al menu\n");
        printf("1.Search substring\n");
        printf("2. Fill string\n");
        printf("3. Extract substring\n");
        printf("4. Replace occurrences\n");
        printf("5. Validates if a string starts with another.\n");
        printf("6. String without characters repeated\n");
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
                result = searchString(string, substring, initialPosition);
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

                fillString(string, character, diretcion, numCharacters);

                printf("Resulting string: %s\n", string);

            break;
            case 3:
                printf("Enter the string: ");
                scanf(" %[^\n]", string);
                printf("Enter the initial position: ");
                scanf("%d", &initialPosition);
                printf("Enter the final position (0 for until the end): ");
                scanf("%d", &finalPosition);

                subsString = extractSubstring(string, initialPosition, finalPosition);

                printf("Resulting string: %s\n", subsString);
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

                printf("Enter the string: ");
                scanf(" %[^\n]", auxOption5);
                printf("Enter the string to verify: ");
                scanf(" %[^\n]", verify);


                result=startsWith(auxOption5,verify);

                printf("If the string meets the condition, the result will be 1; otherwise, it will be 0.\n------------------\n The result is: %d\n", result);

                break;
            case 6:


                printf("Enter the string: ");
                scanf(" %[^\n]", auxOption6);

                removeDuplicates(auxOption6);

                printf("String without duplicate characters: %s\n", auxOption6);
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

int searchString(char *string, char *substring, int initialPosition) {
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


void fillString(char* string, char character, int direction, int numCharacters) {
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

char* extractSubstring(char* string, int initialPosition, int finalPosition) {
    static char subString[100];
    int i, j;

    if (finalPosition == 0) {
        finalPosition = strlen(string);
    }

    if (initialPosition > finalPosition) {
        // Extraer subcadena en forma invertida
        for (i = initialPosition, j = 0; i >= finalPosition; i--, j++) {
            subString[j] = string[i];
        }
    } else {
        // Extraer subcadena normal
        for (i = initialPosition, j = 0; i < finalPosition; i++, j++) {
            subString[j] = string[i];
        }
    }

    subString[j] = '\0';  // Terminar la subcadena con un carácter nulo

    return subString;
}




void replaceCharacter(char *string, char originalChar, char replacementChar) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == originalChar) {
            string[i] = replacementChar;
        }
    }
}

int startsWith(const char *baseString, const char *checkString) {
    int baseLength = strlen(baseString);
    int checkLength = strlen(checkString);

    if (checkLength > baseLength) {
        return 0;
    }

    for (int i = 0; i < checkLength; i++) {
        if (baseString[i] != checkString[i]) {
            return 0; // Mismatch found, not a prefix
        }
    }

    return 1;
}

void removeDuplicates(char *str) {
    int len = strlen(str);
    int index = 0;
    int i, j;

    for (i = 0; i < len; ++i) {
        int found = 0;
        for (j = 0; j < index; ++j) {
            if (str[i] == str[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

