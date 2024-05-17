/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "./libcsfml.h"

int click_sprite
(sfSprite *sprit, sfEvent event, sfRenderWindow *window, sfVector2f size_sprit)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed &&
        mouse.x >= sfSprite_getPosition(sprit).x &&
        mouse.x <= sfSprite_getPosition(sprit).x +
        size_sprit.x &&
        mouse.y >= sfSprite_getPosition(sprit).y &&
        mouse.y <= sfSprite_getPosition(sprit).y +
        size_sprit.y && sfMouse_isButtonPressed(sfMouseLeft)){
            return 1;
        }
    return 0;
}

int click_rectangle
(sfRectangleShape *sprit, sfEvent even, sfRenderWindow *windo, sfVector2f size)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(windo);

    if (even.type == sfEvtMouseButtonPressed &&
        mouse.x >= sfRectangleShape_getPosition(sprit).x &&
        mouse.x <= sfRectangleShape_getPosition(sprit).x +
        size.x &&
        mouse.y >= sfRectangleShape_getPosition(sprit).y &&
        mouse.y <= sfRectangleShape_getPosition(sprit).y +
        size.y){
            return 1;
        }
    return 0;
}

int hover_r(sfRectangleShape *s, sfEvent e, sfRenderWindow *w, sfVector2f si)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w);

    if (mouse.x >= sfRectangleShape_getPosition(s).x &&
        mouse.x <= sfRectangleShape_getPosition(s).x +
        si.x &&
        mouse.y >= sfRectangleShape_getPosition(s).y &&
        mouse.y <= sfRectangleShape_getPosition(s).y +
        si.y){
            return 1;
        }
    return 0;
}

int click_circle
(sfCircleShape *sprit, sfEvent event, sfRenderWindow *window, sfVector2f size)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed &&
        mouse.x >= sfCircleShape_getPosition(sprit).x &&
        mouse.x <= sfCircleShape_getPosition(sprit).x +
        size.x &&
        mouse.y >= sfCircleShape_getPosition(sprit).y &&
        mouse.y <= sfCircleShape_getPosition(sprit).y +
        size.y){
            return 1;
        }
    return 0;
}
