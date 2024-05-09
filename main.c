#include <stdio.h>
#include <malloc.h>

#include "functions.h"

void string_difference();

void insert_substring();

void sort_string();

void read_string(const char *message, char *string, int input_length);

void read_string_without_duplicates(const char *message, char *string, int input_length);

int has_duplicates(const char *string);

int read_integer(const char *message, int min, int max);


int main(void) {
    int option;
    do {
        printf("Bienvenido al menu\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
        printf("4. Opcion 4\n");
        printf("5. Opcion 5\n");
        printf("6. Opcion 6\n");
        printf("7. Difference between strings.\n");
        printf("8. Insert substring.\n");
        printf("9. Sort string\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option) {
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
                printf("Opcion 4\n");
                break;
            case 5:
                printf("Opcion 5\n");
                break;
            case 6:
                printf("Opcion 6\n");
                break;

            case 7: {
                string_difference();
                break;
            }

            case 8: {
                insert_substring();
                break;
            }

            case 9: {
                sort_string();
                break;
            }
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (option != 0);
    return 0;
}


void string_difference() {
    printf("This option calculates the difference between two strings.\n");
    printf("The difference is calculated by subtracting the second string from the first string.\n\n");

    const int input_len = 50;
    char first_str[input_len];
    char second_str[input_len];

    read_string_without_duplicates("Enter the first string: ", first_str, input_len);
    read_string("Enter the second string: ", second_str, input_len);

    char *difference = str_diff(first_str, second_str);

    printf("\n");
    if (difference != NULL) {
        printf("The difference between the strings is: \"%s\"\n\n", difference);
        free(difference);
    } else {
        printf("Error allocating memory.\n\n");
    }
}

void insert_substring() {
    printf("This option allows you to insert a substring into another string at a specific position.\n\n");

    const int input_len = 50;
    char main_string[input_len];
    char substring[input_len];
    int position;

    read_string("Enter the main string: ", main_string, input_len);
    read_string("Enter the substring to insert: ", substring, input_len);

    int max = (int) strlen(main_string);
    position = read_integer("Enter the position to insert the substring: ", 0, max);

    char *result = insert_substr(main_string, substring, position);

    printf("\n");
    if (result != NULL) {
        printf("Resulting string: \"%s\"\n\n", result);
        free(result);
    } else {
        printf("Error allocating memory.\n\n");
    }
}

void sort_string() {
    printf("This option allows you to sort a string in ascending order.\n\n");

    const int input_len = 50;
    char string[input_len];

    read_string("Enter a string to sort: ", string, input_len);

    char *sorted = sort_str(string);

    printf("\n");
    if (sorted != NULL) {
        printf("Sorted string: \"%s\"\n\n", sorted);
        free(sorted);
    } else {
        printf("Error allocating memory.\n\n");
    }
}

void read_string(const char *message, char *string, const int input_length) {
    char buffer[input_length];
    size_t buffer_length;
    do {
        printf("%s", message);
        fgets(buffer, input_length, stdin);

        buffer_length = strlen(buffer);
        if (buffer_length > 0 && buffer[buffer_length - 1] == '\n') {
            buffer[buffer_length - 1] = '\0';
            buffer_length--;
        }

        if (buffer_length == 0) {
            printf("The entered string is empty. Try again.\n\n");
        }

        fflush(stdin);
    } while (buffer_length == 0);

    strcpy(string, buffer);
}

int read_integer(const char *message, int min, int max) {
    int input = -1;

    do {
        printf("%s", message);
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Enter a valid input.\n\n");
            fflush(stdin);
        } else if (input < 0 || input > max) {
            printf("Position out of range. Enter a input between %d and %d.\n", min, max);
        }
    } while (input < 0 || input > max);

    return input;
}

void read_string_without_duplicates(const char *message, char *string, const int input_length) {
    char buffer[input_length];
    int duplicates;

    do {
        read_string(message, buffer, input_length);
        duplicates = has_duplicates(buffer);

        if (duplicates) {
            printf("The entered string contains duplicate characters. Try again.\n\n");
        }
    } while (duplicates);

    strcpy(string, buffer);
}

int has_duplicates(const char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        for (int j = i + 1; string[j] != '\0'; j++) {
            if (string[i] == string[j]) {
                return 1;
            }
        }
    }
    return 0;
}