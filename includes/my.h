/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include "../libCSFML/libcsfml.h"
#include "struct.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#ifndef FUNC_H
    #define FUNC_H
    #define ISPRESSED sfKeyboard_isKeyPressed

void start_runner(window_t window);
void win(window_t window);
void win_screen(window_t window);

#endif /*FUNC_H*/
