/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "./libcsfml.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

sfSprite *creat_sprite_with_texture(char *image, int x, int y, float size)
{
    sfVector2f pos = {x, y};
    sfTexture *texture = sfTexture_createFromFile(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f size_sprite = {size, size};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size_sprite);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void deplacement_sprite(sfSprite *sprite, float vit_x, float vit_y)
{
    sfVector2f new_pos = {sfSprite_getPosition(sprite).x + vit_x,
    sfSprite_getPosition(sprite).y + vit_y};

    sfSprite_setPosition(sprite, new_pos);
}

sfText *creat_text
(char *text2, sfVector2i pos, float size, sfColor color)
{
    sfFont *font = sfFont_createFromFile
        ("libCSFML/arial.ttf");
    sfText *text = sfText_create();
    sfVector2f move_text = {pos.x, pos.y};

    sfText_setString(text, text2);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_move(text, move_text);
    sfText_setFillColor(text, color);
    return text;
}

sfRenderWindow *creat_window(int x, int y, char *name, sfUint32 screen)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, name, screen | sfClose, NULL);
    return window;
}
