/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../src/structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

char *my_strcat(char *, char const *);
backgrounds_t *create_background();
mousing_t *the_mouse(mousing_t *, superior_struct_t *);
int close_and_hitbox(superior_struct_t *);
int out_of_the_screen(superior_struct_t *, mousing_t *);
int life_of_char(int , superior_struct_t *);
sprites_t *print_score(int , superior_struct_t *);
sprites_t *create_sprite();
music_t *set_music();
init_t *initialize_it();
char *int_to_str(int, char *);
int my_strlen(char const *);
int my_strcmp(char const *, char const *);
char *my_strdup(char const *src);
char *my_revstr(char *str);
char *my_putstr(char *);