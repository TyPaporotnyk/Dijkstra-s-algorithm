#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;

/* Create the main window */
    window = sfRenderWindow_create(mode, "CSFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}