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
