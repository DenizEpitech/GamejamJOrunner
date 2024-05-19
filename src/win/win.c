/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "../../includes/my.h"

static void print_win_screen(window_t window, sfSprite *win_image, sfSprite **buttons)
{
    sfRenderWindow_drawSprite(window.window, win_image, NULL);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window.window, buttons[i], NULL);
    sfRenderWindow_display(window.window);
    sfRenderWindow_clear(window.window, sfWhite);
}

static int click_win_buttons(sfSprite **buttons, window_t window)
{
    sfVector2f size_rect = {300, 100};

    if (click_sprite(buttons[0], window.event, window.window, size_rect))
        return 1;
    if (click_sprite(buttons[1], window.event, window.window, size_rect))
        sfRenderWindow_close(window.window);
    return 0;
}

void win_screen(window_t window)
{
    sfSprite *win_image = creat_sprite_with_texture("victory.png", 0, 0, 1);
    sfSprite **buttons = malloc(sizeof(sfSprite *) * 2);

    buttons[0] = creat_sprite_with_texture("home.png", 700, 450, 1);
    buttons[1] = creat_sprite_with_texture("exit.png", 700, 600, 1);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            close_window(window.window, window.event);
        print_win_screen(window, win_image, buttons);
        if (click_win_buttons(buttons, window))
            return;
    }
    sfSprite_destroy(win_image);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(buttons[i]);
    free(buttons);
}

void win(window_t window)
{
    win_screen(window);
}

