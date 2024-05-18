/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/

#include "../../includes/my.h"
#include "../../includes/struct.h"

static menu_t create_struct_menu(void)
{
    menu_t menu;

    menu.sprite_menu = malloc(sizeof(sfSprite *) * 2);
    menu.bouton = malloc(sizeof(sfSprite *) * 2);
    menu.sprite_menu[0] = creat_sprite_with_texture("src/menu/fondmenu.png", 0, 0, 1);
    menu.bouton[0] = creat_sprite_with_texture("src/menu/start.png", 700, 450, 1);
    menu.bouton[1] = creat_sprite_with_texture("src/menu/exit.png", 700, 795, 1);
    return menu;
}

static void menu_destroy(menu_t menu)
{
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(menu.bouton[i]);
    sfSprite_destroy(menu.sprite_menu[0]);
    free(menu.bouton);
    free(menu.sprite_menu);
}

static int click_menu(menu_t menu, window_t window)
{
    sfVector2f size_rect = {500, 150};

    if (click_sprite(menu.bouton[0], window.event, window.window, size_rect))
        return 1;
    if (click_sprite(menu.bouton[1], window.event, window.window, size_rect))
        sfRenderWindow_close(window.window);
    return 0;
}

static void print_menu(window_t window, menu_t menu)
{
    sfRenderWindow_drawSprite(window.window, menu.sprite_menu[0], NULL);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window.window, menu.bouton[i], NULL);
    sfRenderWindow_display(window.window);
    sfRenderWindow_clear(window.window, sfWhite);
}

void menu(window_t window)
{
    menu_t menu = create_struct_menu();

    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            close_window(window.window, window.event);
        print_menu(window, menu);
        if (click_menu(menu, window))
            return;
    }
}

window_t start_runner(void)
{
    window_t window = {.window = creat_window(1920, 1080, "MY_JO_RUNNER", sfResize), .clock = sfClock_create()};
    
    window.time = sfClock_getElapsedTime(window.clock);
    menu(window);
    return window;
}
