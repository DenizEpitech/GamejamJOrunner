/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include "../includes/my.h"

static int condition_up(perso_t perso, window_t window)
{
    sfVector2f pos = sfSprite_getPosition(perso.pesro);

    if (ISPRESSED(sfKeyUp)){
        sfRenderWindow_drawText(window.window, creat_text("You are cheating !!!\n", (sfVector2i){100, 100}, 50, sfWhite), NULL);
        return -1;
    }
    if (ISPRESSED(sfKeySpace) && perso.up == 0)
        return -1;
    if (pos.y < 450 && perso.up == -1)
        return 1;
    if (pos.y > 600 && perso.up == 1)
        return 0;
    return perso.up;
}

static void moove_perso(perso_t *perso, window_t window)
{
    perso->time_perso = sfClock_getElapsedTime(perso->clock_perso);
    perso->up = condition_up(*perso, window);
    if (sfTime_asSeconds(perso->time_perso) > 0.085){
        if (perso->perso_str[15] == '9')
            perso->perso_str[15] = '2';
        perso->perso_str[15]++;
        perso->pesro = sprite_set_new_texture(perso->pesro, perso->perso_str);
        deplacement_sprite(perso->pesro, 0, 25 * perso->up);
        sfClock_restart(perso->clock_perso);
    }
}

static void obstacle_deplacement(window_t *window, sfSprite **obstacle)
{
    window->time = sfClock_getElapsedTime(window->clock);
    for (int i = 0; i < 2; i++)
        if (sfSprite_getPosition(obstacle[i]).x < -20)
            sfSprite_setPosition(obstacle[i], (sfVector2f){(rand() % 500) + 2000, sfSprite_getPosition(obstacle[i]).y});
    if (sfTime_asSeconds(window->time) > 0.005){
        for (int i = 0; i < 2; i++)
            deplacement_sprite(obstacle[i], -4, 0);
        sfClock_restart(window->clock);
    }
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window->window, obstacle[i], NULL);
}

static int win_or_loose(perso_t perso, sfSprite **obstacle, sfSprite *paris)
{
    sfVector2f pos_perso = sfSprite_getPosition(perso.pesro);//180 size 
    sfVector2f pos_1 = sfSprite_getPosition(obstacle[0]);//204.8 size
    sfVector2f pos_2 = sfSprite_getPosition(obstacle[1]);

    if ((pos_perso.x + 100 > pos_1.x + 20 && pos_perso.y + 100 > pos_1.y) && (pos_perso.x < pos_1.x + 200 && pos_perso.y + 150 < pos_1.y + 200))
        return 1;
    if ((pos_perso.x + 100 > pos_2.x + 20 && pos_perso.y + 100 > pos_2.y) && (pos_perso.x < pos_2.x + 200 && pos_perso.y + 150 < pos_2.y + 200))
        return 1;
    if (sfSprite_getPosition(paris).x < -2500)
        return 2;
    return 0;
}

static void deplacement_back(window_t window)
{
    deplacement_sprite(window.bas_1, -0.10, 0);
    deplacement_sprite(window.bas_2, -0.10, 0);
    if (sfSprite_getPosition(window.bas_1).x < -2150)
        sfSprite_setPosition(window.bas_1, (sfVector2f){2150, 700});
    if (sfSprite_getPosition(window.bas_2).x < -2150)
        sfSprite_setPosition(window.bas_2, (sfVector2f){2150, 700});
}

static void start(window_t window, int boo)
{
    if (boo)
        start_runner(window);
    sfSprite **obstacle = malloc(sizeof(sfSprite *) * 2);
    sfSprite *image_fond = creat_sprite_with_texture("marseille.png", 0, 0, 0.92);
    sfSprite *image_fond_2 = creat_sprite_with_texture("paris.png", 3700, 0, 0.92);
    obstacle[0] = creat_sprite_with_texture("./obs.png", 2500, 650, 0.2);
    obstacle[1] = creat_sprite_with_texture("./obs.png", 3500, 650, 0.2);
    perso_t perso = {.pesro = creat_sprite_with_texture("./src/perso/run1.png", 860, 600, 2), .perso_str = "./src/perso/run1.png", .clock_perso = sfClock_create(), .up = 0};

    window.time = sfClock_getElapsedTime(window.clock);
    perso.time_perso = sfClock_getElapsedTime(perso.clock_perso);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            close_window(window.window, window.event);
        sfRenderWindow_drawSprite(window.window, image_fond, NULL);  //la c'est le 1er si non beug
        sfRenderWindow_drawSprite(window.window, image_fond_2, NULL);  //la c'est le 1er si non beug
        sfRenderWindow_drawSprite(window.window, window.bas_1, NULL);//la c'est le 2eme si non beug
        sfRenderWindow_drawSprite(window.window, window.bas_2, NULL);//la c'est le 3eme si non beug
        deplacement_back(window);                                    //deplacement du sol
        deplacement_sprite(image_fond, -0.10, 0);
        deplacement_sprite(image_fond_2, -0.10, 0);                    //deplacement de l'mage du fond les ville  
        obstacle_deplacement(&window, obstacle);
        moove_perso(&perso, window);
        sfRenderWindow_drawSprite(window.window, perso.pesro, NULL);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfWhite);
        if (win_or_loose(perso, obstacle, image_fond_2) == 1)
            start(window, 1);
        if (win_or_loose(perso, obstacle, image_fond_2) == 2)
            return win(window);
    }
}

int main()
{
    window_t window = {.window = creat_window(1920, 1080, "MY_JO_RUNNER", sfResize), .clock = sfClock_create(), .bas_1 = creat_sprite_with_texture("./bas.jpeg", 0, 700, 0.5), 
    .bas_2 = creat_sprite_with_texture("./bas2.jpeg", 2150, 700, 0.5)};

    window.time = sfClock_getElapsedTime(window.clock);
    start_runner(window);
    start(window, 0);
}
