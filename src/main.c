/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "../includes/my.h"

static void obstacle_deplacement(window_t *window, sfSprite **obstacle)
{
    window->time = sfClock_getElapsedTime(window->clock);
    for (int i = 0; i < 2; i++)
        if (sfSprite_getPosition(obstacle[i]).x < -20)
            sfSprite_setPosition(obstacle[i], (sfVector2f){(rand() % 1500) + 2000, sfSprite_getPosition(obstacle[i]).y});
    if (sfTime_asSeconds(window->time) > 0.005){
        for (int i = 0; i < 2; i++)
            deplacement_sprite(obstacle[i], -1, 0);
        sfClock_restart(window->clock);
    }
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window->window, obstacle[i], NULL);
}

int main(void)
{
    sfSprite **obstacle = malloc(sizeof(sfSprite *) * 2);
    obstacle[0] = creat_sprite_with_texture("./obs.png", 2500, 600, 0.2);
    obstacle[1] = creat_sprite_with_texture("./obs.png", 3500, 600, 0.2);
    window_t window = {.window = creat_window(1920, 1080, "MY_JO_RUNNER", sfResize), .clock = sfClock_create()};
    all_t all = {.bas = creat_sprite_with_texture("./bas.jpeg", 0, 700, 0.5), .pesro = creat_sprite_with_texture("./src/perso/run1.png", 960, 700, 0.5)};

    window.time = sfClock_getElapsedTime(window.clock);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            close_window(window.window, window.event);
        sfRenderWindow_drawSprite(window.window, all.bas, NULL);                            //la c'est le 1er si non beug
        obstacle_deplacement(&window, obstacle);
        sfRenderWindow_drawSprite(window.window, all.pesro, NULL);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfWhite);
    }
}