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


char *insert_substr(const char *base_str, const char *substr, int position) {
    int base_len = string_length(base_str);
    int substr_len = string_length(substr);

    if (position < 0 || position > base_len) {
        return NULL;
    }

    int total_len = base_len + substr_len + 1;

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
