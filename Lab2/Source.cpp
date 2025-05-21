#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

void handle_movement_keys(ALLEGRO_EVENT event);

int main() {

	if (!al_init()) {
		std::cerr << "Failed to initialize Allegro!" << std::endl;
	}

	ALLEGRO_DISPLAY* display = NULL;
	display = al_create_display(800, 600);
	if(!display) {
		std::cerr << "Display did not initialize!" << std::endl;
		return -1;
	}
	al_init_primitives_addon();

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT event;
	event_queue = al_create_event_queue();

	if (!event_queue) {
		std::cerr << "Event queue did not initialize!" << std::endl;
		return -1;
	}

	if(!al_install_keyboard()) {
		std::cerr << "Keyboard not found!" << std::endl;
		return -1;
	}
	// Allow keyboard events to be processed
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (true) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_circle(400, 300, 50, al_map_rgb(255, 50, 50), 5);
		// The listener for the event queue
		al_wait_for_event(event_queue, &event);
		// Check if the event is a movement key
		handle_movement_keys(event);
		al_flip_display();
	}

	return 0;
}

void handle_movement_keys(ALLEGRO_EVENT event) {
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				std::cout << "Up key pressed!" << std::endl;
				break;
			case ALLEGRO_KEY_DOWN:
				std::cout << "Down key pressed!" << std::endl;
				break;
			case ALLEGRO_KEY_LEFT:
				std::cout << "Left key pressed!" << std::endl;
				break;
			case ALLEGRO_KEY_RIGHT:
				std::cout << "Right key pressed!" << std::endl;
				break;
		}
	}
}