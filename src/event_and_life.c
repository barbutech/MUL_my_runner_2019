/*
** EPITECH PROJECT, 2019
** events_and_life
** File description:
** event and life
*/

#include "../include/my.h"
#include "structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

int music(sfEvent event, superior_struct_t *main, sfVector2f mouse_float, sfVector2f hitbox)
{
    int spawn = rand() % 600;

     if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyLControl)
            && sfKeyboard_isKeyPressed(sfKeyQ))
                sfRenderWindow_close(main->init->window);
            if (event.type == sfEvtMouseButtonPressed) {
            if (mouse_float.x >= hitbox.x && mouse_float.x <= hitbox.x + 57
            && sfMouse_isButtonPressed(sfMouseLeft))
                if (mouse_float.y >= hitbox.y && mouse_float.y <= hitbox.y + 106 ) {
                    sfMusic *music = sfMusic_createFromFile("link-scream-attack-3.wav");
                    sfMusic_play(music);
                    sfSprite_setPosition(main->the_sprite->sprite, (sfVector2f){-50, spawn});
                    return (1);
                }
            }
        return (0);
}

int close_and_hitbox(superior_struct_t *main)
{
    sfVector2f mouse_float;
    sfEvent event;
    sfVector2f hitbox = sfSprite_getPosition(main->the_sprite->sprite);
    sfVector2i mouse = sfMouse_getPosition((sfWindow*)main->init->window);

    mouse_float.x = (float)mouse.x - 18;
    mouse_float.y = (float)mouse.y - 10;
    while (sfRenderWindow_pollEvent(main->init->window, &event)) {
        if (music(event, main, mouse_float, hitbox) == 1)
        return (1);
    }
    return (0);
}

int out_of_the_screen(superior_struct_t *main, mousing_t *cursor)
{
    int spawn = rand() % 600;
    sfVector2f mouse_float;

    sfVector2f sprite_pos = sfSprite_getPosition(main->the_sprite->sprite);
    sfVector2i mouse = sfMouse_getPosition((sfWindow*)main->init->window);
    mouse_float.x = (float)mouse.x - 18;
    mouse_float.y = (float)mouse.y - 10;
    sfSprite_setPosition(cursor->mouse_curs, mouse_float);
    sfRenderWindow_drawSprite(main->init->window, cursor->mouse_curs, NULL);

    sfTime time = sfClock_getElapsedTime(main->init->clock);

    if (sprite_pos.x >= 1024) {
        sfSprite_setPosition(main->the_sprite->sprite, (sfVector2f){-50, spawn});
        return (1);
    }
    return (0);
}

sprites_t *print_score(int score, superior_struct_t *main)
{
    sprites_t *print_score = malloc(sizeof(print_score));
    char *str = "score : ";
    char *score_str = int_to_str(score, str);
    sfFont *font = sfFont_createFromFile("Triforce.ttf");

    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, score_str);
    sfText_setPosition(text, (sfVector2f){1, 0});
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(main->init->window, text, NULL);
}

int life_of_char(int life, superior_struct_t *main)
{
    sfVector2f sprite_pos = sfSprite_getPosition(main->the_sprite->sprite);
    char *str = "life : ";
    if (sprite_pos.x >= 1024)
        life = life -1;
        char *life_str = int_to_str(life, str);
    sfFont *font = sfFont_createFromFile("Triforce.ttf");

    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, life_str);
    sfText_setPosition(text, (sfVector2f){900, 0});
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(main->init->window, text, NULL);
        return (life);
}