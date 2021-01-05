/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicate a str
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;
    int size = 0;

    while (src[size] != '\0')
        size = size + 1;
    dest = malloc(sizeof(char) * (size + 1));
    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
