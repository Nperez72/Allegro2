#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

void handle_movement_keys(ALLEGRO_EVENT event, float& x, float& y);

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

	// Initliaze the event queue to handle keyboard events
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
	// Allow keyboard interaction into event queue
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	// Initial circle position
	float circle_x = 400;
	float circle_y = 300;

	while (true) {
		// Clear the display with a black color (gets rid of the previous circle)
		al_clear_to_color(al_map_rgb(0, 0, 0));
		// Draw the circle at the new position
		al_draw_circle(circle_x, circle_y, 25, al_map_rgb(255, 50, 50), 5);
		// Swap buffers and display the new circle
		al_flip_display();
		// The listener for the event queue
		al_wait_for_event(event_queue, &event);
		// Check if the event is a movement key
		handle_movement_keys(event, circle_x, circle_y);	
	}

	return 0;
}

/*
* Function to handle all valid movement keys to update the circle position,
* both x and y coordinates. Only gets the down press of a key.
* All conditional logic for key events are handled here to make game loop cleaner.
*/
void handle_movement_keys(ALLEGRO_EVENT event, float &x, float &y) {
	float move_amount = 5.0f;
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				y -= move_amount;
				break;
			case ALLEGRO_KEY_DOWN:
				y += move_amount;
				break;
			case ALLEGRO_KEY_LEFT:
				x -= move_amount;
				break;
			case ALLEGRO_KEY_RIGHT:
				x += move_amount;
				break;
		}
	}
}