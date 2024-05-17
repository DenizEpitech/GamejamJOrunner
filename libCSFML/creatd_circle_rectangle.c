/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "./libcsfml.h"

sfRectangleShape *creat_sqare(sfVector2f pos_square, float size2, sfColor c)
{
    sfVector2f size = {size2, size2};
    sfRectangleShape *re = sfRectangleShape_create();

    sfRectangleShape_setPosition(re, pos_square);
    sfRectangleShape_setFillColor(re, c);
    sfRectangleShape_setSize(re, size);
    return re;
}

sfRectangleShape *creat_sqare_contour(sfVector2f pos_s, float size2, sfColor c)
{
    sfVector2f size = {size2, size2};
    sfRectangleShape *re = sfRectangleShape_create();

    sfRectangleShape_setPosition(re, pos_s);
    sfRectangleShape_setFillColor(re, sfTransparent);
    sfRectangleShape_setOutlineThickness(re, 3);
    sfRectangleShape_setOutlineColor(re, c);
    sfRectangleShape_setSize(re, size);
    return re;
}

sfRectangleShape *creat_rectangle
(sfVector2f ps_s, float s2, float s3, sfColor c)
{
    sfVector2f size = {s2, s3};
    sfRectangleShape *re = sfRectangleShape_create();

    sfRectangleShape_setPosition(re, ps_s);
    sfRectangleShape_setFillColor(re, c);
    sfRectangleShape_setSize(re, size);
    return re;
}

sfCircleShape *creat_circle(sfVector2f pos_circle, float size, sfColor c)
{
    sfCircleShape *re = sfCircleShape_create();

    sfCircleShape_setPosition(re, pos_circle);
    sfCircleShape_setFillColor(re, c);
    sfCircleShape_setRadius(re, size);
    return re;
}
