#include <malloc.h>

#include "functions.h"

int string_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


int character_exists(const char *source, char target) {
    int str_len = string_length(source);
    int i = 0;
    while (i < str_len && source[i] != target) {
        i++;
    }

    return i < str_len;
}

char *str_diff(const char *first_str, const char *second_str) {
    int first_len = string_length(first_str);
    string_length(second_str);

    char *result = (char *) malloc(sizeof(char) * (first_len + 1));
    if (!result) {
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < first_len; i++) {
        char target = first_str[i];
        if (!character_exists(second_str, target)) {
            result[k] = target;
            k++;
        }
    }

    result[k] = '\0';

    return result;
}
