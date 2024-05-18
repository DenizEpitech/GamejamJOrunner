/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct ilann
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef STRUCT_H_
    #define STRUCT_H_
typedef struct window {
    sfRenderWindow *window;
    sfTime time;
    sfClock *clock;
    sfEvent event;
}window_t;

typedef struct all {
    sfSprite *pesro;
    sfSprite *bas;
    char perso_str[22];
    sfClock *clock_perso;
    sfTime time_perso;
}all_t;

typedef struct menu {
    sfSprite *image_window;
    sfSprite **bouton;
    sfSprite **sprite_menu;
}menu_t;

#endif
