#include <malloc.h>
#include <string.h>

#include "functions.h"


char *str_diff(const char *first_str, const char *second_str) {
    size_t first_len = strlen(first_str);

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

int character_exists(const char *source, const char target) {
    size_t str_len = strlen(source);
    int i = 0;
    while (i < str_len && source[i] != target) {
        i++;
    }

    return i < str_len;
}
