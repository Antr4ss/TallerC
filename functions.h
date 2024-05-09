#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <malloc.h>
#include <string.h>
#include <ctype.h>

char *str_diff(const char *first_str, const char *second_str);

char *insert_substr(const char *base_str, const char *substr, int position);

char *sort_str(const char *src);

#endif //FUNCTIONS_H
