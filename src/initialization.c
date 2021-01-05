/*
** EPITECH PROJECT, 2019
** init
** File description:
** init of my_hunter
*/

#include "structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

backgrounds_t *create_background()
{
    backgrounds_t *backgrnd = malloc(sizeof(backgrounds_t));
    backgrnd->backgr = sfTexture_createFromFile("Lost_Woods_Majoras_Mask.png", NULL);
    backgrnd->background = sfSprite_create();
    sfSprite_setTexture(backgrnd->background, backgrnd->backgr, sfTrue);
    sfSprite_scale(backgrnd->background, (sfVector2f){1, 1.5});
    return (backgrnd);
}

sprites_t *create_sprite()
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile("mask.png", NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}

mousing_t *the_mouse(mousing_t *cursor, superior_struct_t *main)
{
    sfWindow_setMouseCursorVisible((sfWindow*)main->init->window, 0);
    cursor->mouse_text = sfTexture_createFromFile("sword.png", NULL);
    cursor->mouse_curs = sfSprite_create();
    sfSprite_setTexture(cursor->mouse_curs, cursor->mouse_text, sfTrue);
    sfVector2f mouse_float;
}

music_t *set_music()
{
    music_t *musics = malloc(sizeof(music_t));
    musics->music = sfMusic_createFromFile("lostwoods.ogg");
    sfMusic_setLoop(musics->music, sfTrue);
    sfMusic_play(musics->music);
    return (musics);
}

init_t *initialize_it()
{
    init_t *init = malloc(sizeof(init_t));
    sfVideoMode mode = {1024, 768, 32};
    init->window = sfRenderWindow_create(mode, "My_runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(init->window, 60);

    init->clock = sfClock_create();
    return (init);
}