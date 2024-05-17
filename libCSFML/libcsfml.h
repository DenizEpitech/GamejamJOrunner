/*
** EPITECH PROJECT, 2023
** lib.h
** File description:
** lib.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>

#ifndef LIB_H_CSFML
    #define LIB_H_CSFML

char *int_to_str(int nbr);
void close_window(sfRenderWindow *window, sfEvent event);
sfSprite *creat_sprite_with_texture(char *image, int x, int y, float size);
void deplacement_sprite(sfSprite *sprite, float vit_x, float vit_y);
sfText *creat_text(char *text2, sfVector2i pos, float size, sfColor color);
sfRenderWindow *creat_window(int x, int y, char *name, sfUint32 screen);
int click_sprite(sfSprite *, sfEvent, sfRenderWindow *, sfVector2f);
int click_rectangle(sfRectangleShape *, sfEvent, sfRenderWindow *, sfVector2f);
sfRectangleShape *creat_sqare(sfVector2f pos_square, float size, sfColor c);
sfRectangleShape *creat_rectangle
(sfVector2f ps_s, float s2, float s3, sfColor c);
sfCircleShape *creat_circle(sfVector2f pos_circle, float size, sfColor c);
int click_circle(sfCircleShape *, sfEvent, sfRenderWindow *, sfVector2f);
int hover_r(sfRectangleShape *s, sfEvent e, sfRenderWindow *w, sfVector2f si);
sfRectangleShape *creat_sqare_contour(sfVector2f pos_s, float s, sfColor c);
sfSprite *sprite_set_new_texture(sfSprite *, char *);
#endif /*LIB_H_CSFML*/
