#include "game.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

#define FREQ_UPDATE 1. / 30
#define FREQ_FRAME 1. / 60

using cr::game;

void
main_loop(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMER *frame_timer)
{
    game game;
    ALLEGRO_EVENT event;
    bool running = true;
    double last_update_time, current_time;
    const double minimum_update_frequency = FREQ_UPDATE;

    current_time = al_get_time();

    game.init_update(current_time);
    game.draw();
    al_flip_display();
    last_update_time = current_time;

    while (running) {
        al_wait_for_event(event_queue, &event);

        current_time = al_get_time();

        switch (event.type) {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            running = false;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                running = false;
            break;
        case ALLEGRO_EVENT_TIMER:
            for (;;) {
                double update_time = last_update_time + minimum_update_frequency;
                if (update_time >= current_time)
                    break;
                game.update(nullptr, update_time);
                last_update_time = update_time;
            }

            if (event.timer.source == frame_timer) {
                game.update(&event, current_time);
                game.draw();
                al_flip_display();
                last_update_time = current_time;
            }

            break;
        }
    }
}

int
main()
{
    if (!al_init()) {
        std::cerr << "error initializing allegro" << std::endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    if (display == nullptr) {
        std::cerr << "error creating allegro display" << std::endl;
        return 1;
    }

    if (!al_install_keyboard()) {
        std::cerr << "error installing allegro keyboard" << std::endl;
        return 1;
    }

    if (!al_init_primitives_addon()) {
        std::cerr << "error initializing allegro primitives addon" << std::endl;
        return 1;
    }

    ALLEGRO_TIMER *timer = al_create_timer(FREQ_FRAME);
    if (display == nullptr) {
        std::cerr << "error creating allegro timer" << std::endl;
        return 1;
    }

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if (event_queue == nullptr) {
        std::cerr << "error creating allegro event queue" << std::endl;
        return 1;
    }

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);

    main_loop(event_queue, timer);

    al_stop_timer(timer);

    al_unregister_event_source(event_queue, al_get_display_event_source(display));
    al_unregister_event_source(event_queue, al_get_timer_event_source(timer));
    al_unregister_event_source(event_queue, al_get_keyboard_event_source());

    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    al_shutdown_primitives_addon();
    al_uninstall_keyboard();

    al_destroy_display(display);

    al_uninstall_system();

    return 0;
}

// vim:set sw=4 ts=4 et:
