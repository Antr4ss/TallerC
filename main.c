#include <stdio.h>
#include <string.h>

void replaceCharacter(char *string, char originalChar, char replacementChar);

int startsWith(const char *baseString, const char *checkString);

void removeDuplicates(char *str);

int main(void) {

    char auxOption4 [50];
    char auxOption5 [50];
    char auxOption6 [50];
    char verify [50];
    char char1Option4;
    char char2Option4;
    int result;
    int option;
    do {
        printf("Bienvenido al menu\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
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

