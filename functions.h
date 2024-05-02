#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int string_length(const char *str);

int character_exists(const char *source, char target);

char *str_diff(const char *first_str, const char *second_str);

char *insert_substr(const char *base_str, const char *substr, int position);

#endif //FUNCTIONS_H
