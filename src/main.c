/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** apprendre le CSFML
*/

#include "../include/my.h"
#include "structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

int anime_my_sprite(superior_struct_t *main, int i)
{
    sfIntRect rect = (sfIntRect){i, 0, 38, 34};
    sfTime time = sfClock_getElapsedTime(main->clock);
    if (sfTime_asMilliseconds(time) > 70) {
        i = i + 40;
        sfClock_restart(main->clock);
    }
    if (i >240)
        i = 0;
    sfSprite_setTextureRect(main->the_sprite->sprite, rect);
    sfRenderWindow_drawSprite(main->init->window, main->the_sprite->sprite, NULL);
    return (i);
}

int print_h(int ac, char **argv)
{
    char *verif = "-h";

    if (ac == 2 && my_strcmp(argv[1], verif) == 0) {
            my_putstr("the majora's mask attack the skull kids !! hurry up you have to click on the masks with the left mouse button to destroy them and save the skull kids.\n");
            return (0);
    }
    return (1);
}

superior_struct_t *create_main()
{
    superior_struct_t *main = malloc(sizeof(superior_struct_t));

    main->backgrnd = create_background();;
    main->the_sprite = create_sprite();;
    main->init = initialize_it();
    main->musics = set_music();
    main->clock = sfClock_create();
    return (main);
}

int loop(superior_struct_t *main, mousing_t *cursor)
{
    int life = 6;
    int i = 0;
    float speed = 1;
    int score = 0;

    while (sfWindow_isOpen((sfWindow*)main->init->window)) {
        sfRenderWindow_drawSprite(main->init->window, main->backgrnd->background, NULL);
        i = anime_my_sprite(main, i);
        life = life_of_char(life, main);
        if (life == 0)
            return (0);
        if (close_and_hitbox(main) == 1) {
            score = score + 100;
            speed = speed + 0.5;
        }
        print_score(score, main);
        if (out_of_the_screen(main, cursor) == 1)
            speed = speed + 0.5;
        sfSprite_move(main->the_sprite->sprite, (sfVector2f){speed, 0});
        sfRenderWindow_display(main->init->window);
    }
}

int main(int argc, char **argv)
{
    if (print_h(argc, argv) == 0)
        return (0);
    superior_struct_t *main = create_main();
    mousing_t cursor;

    the_mouse(&cursor, main);
    loop(main, &cursor);
    sfSprite_destroy(main->the_sprite->sprite);
    sfSprite_destroy(main->backgrnd->background);
    sfMusic_destroy(main->musics->music);
    return (0);
}
