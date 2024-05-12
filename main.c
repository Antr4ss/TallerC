#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Replaces all occurrences of a character with another character in a given string.
 *
 * @param string The string in which the replacement will be performed.
 * @param originalChar The character to be replaced.
 * @param replacementChar The character to replace the original character.
 *
 * This function replaces all occurrences of the originalChar character in the string with the replacementChar character.

 */
void replaceCharacter(char *string, char originalChar, char replacementChar);

/**
 * Validates whether a string starts with another string.
 *
 * @param baseString The base string to check against.
 * @param checkString The string to verify whether it starts with the base string.
 *
 * @return
 *     1 if the checkString starts with the baseString.
 *     0 if the checkString does not start with the baseString.
 *
 * This function checks if the checkString starts with the baseString.
 * It returns 1 if the checkString starts with the baseString, otherwise it returns 0.

 */
int startsWith(const char *baseString, const char *checkString);
/**
 * Remove duplicate characters from a string.
 *
 * @param str The string to remove duplicates from.
 *
 * This function removes duplicate characters from the given string.
 *
 */
void removeDuplicates(char *str);


void removeDuplicates(char *str);
int searchString(char *string, char *substring, int initialPosition);
void fillString(char* string, char character, int direction, int numCharacters);
char* extractSubstring(char* string, int posInicial, int posFinal);

/**
 * Calculates the difference between two strings, removing characters of the second string from the first one.
 * @param first_str The first string.
 * @param second_str The second string.
 * @return A new string representing the difference between the two strings.
 */
char *str_diff(const char *first_str, const char *second_str);


/**
 * Inserts a substring into a main string at a specific position.
 * @param base_str The main string.
 * @param substr The substring to insert.
 * @param position The position at which to insert the substring.
 * @return A new string resulting from the insertion of the substring at the specified position.
 */
char *insert_substr(const char *base_str, const char *substr, int position);


/**
 * Sorts a string of characters in alphabetical order.
 * @param src The string to sort.
 * @return A new string representing the sorted string.
 */
char *sort_str(const char *src);


/**
 * Displays a message and prompts for two strings to calculate their difference using `str_diff`.
 */
void string_difference();


/**
 * Displays a message and prompts for a main string, a substring, and a position to insert the substring, using `insert_substr`.
 */
void insert_substring();


/**
 * Displays a message and prompts for a string to sort alphabetically using `sort_str`.
 */
void sort_string();


/**
 * Reads a string of characters from standard input.
 * @param message The message displayed when requesting input.
 * @param string The read string will be stored here.
 * @param input_length The maximum length of the input string.
 */
void read_string(const char *message, char *string, int input_length);


/**
 * Reads an integer from standard input within a specific range.
 * @param message The message displayed when prompting for input.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return The valid integer read.
 */
int read_integer(const char *message, int min, int max);


/**
 * Reads a string of characters from standard input and checks if it contains duplicate characters.
 * @param message The message displayed when requesting input.
 * @param string The read string will be stored here.
 * @param input_length The maximum length of the input string.
 */
void read_string_without_duplicates(const char *message, char *string, int input_length);


/**
 * Checks if a string of characters contains duplicate characters.
 * @param string The string to check.
 * @return 1 if the string has duplicates, 0 otherwise.
 */
int has_duplicates(const char *string);

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
        printf("Welcome to the C workshop\n");
        printf("1.Search substring\n");
        printf("2. Fill string\n");
        printf("3. Extract substring\n");
        printf("4. Replace occurrences\n");
        printf("5. Validates if a string starts with another.\n");
        printf("6. String without characters repeated\n");
        printf("7. Difference between strings.\n");
        printf("8. Insert substring.\n");
        printf("9. Sort string\n");
        printf("10. Exit\n");
        printf("Select an option:");
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

            case 10:
                printf("Thank you for using our program.\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while(option!=10);
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

char *str_diff(const char *first_str, const char *second_str) {
    size_t first_len = strlen(first_str);

    char *result = (char *) malloc(sizeof(char) * (first_len + 1));
    if (!result) {
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < first_len; i++) {
        char target = first_str[i];
        if (!strchr(second_str, target)) {
            result[k] = target;
            k++;
        }
    }

    result[k] = '\0';

    return result;
}

char *insert_substr(const char *base_str, const char *substr, const int position) {
    size_t base_len = strlen(base_str);
    size_t substr_len = strlen(substr);

    if (position < 0 || position > base_len) {
        return NULL;
    }

    size_t total_len = base_len + substr_len + 1;

    char *result = malloc(sizeof(char) * total_len);
    if (!result) {
        return NULL;
    }

    for (int i = 0; i < position; ++i) {
        result[i] = base_str[i];
    }

    for (int i = 0; i < substr_len; ++i) {
        result[position + i] = substr[i];
    }

    for (int i = position; i < total_len; ++i) {
        result[substr_len + i] = base_str[i];
    }

    result[total_len - 1] = '\0';
    return result;
}

char *sort_str(const char *src) {
    size_t len = strlen(src);

    char *result = (char *)malloc(len + 1);
    if (!result) {
        return NULL;
    }

    strcpy(result, src);

    for (size_t i = 0; i < len - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < len; ++j) {
            if (tolower(result[j]) < tolower(result[min_index])) {
                min_index = j;
            }
        }

        if (min_index != i) {
            char temp = result[i];
            result[i] = result[min_index];
            result[min_index] = temp;
        }
    }

    return result;
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
