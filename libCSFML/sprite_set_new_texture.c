/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "./libcsfml.h"

sfSprite *sprite_set_new_texture
(sfSprite *sprite, char *str)
{
    const sfTexture *texture = sfTexture_createFromFile(str, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
