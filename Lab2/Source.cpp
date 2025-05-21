#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

int main() {

	if (!al_init()) {
		std::cerr << "Failed to initialize Allegro!" << std::endl;
	}

	ALLEGRO_DISPLAY* display = NULL;
	display = al_create_display(800, 600);
	if(!display) {
		std::cerr << "Display did not initialize properly!" << std::endl;
		return -1;
	}
	al_init_primitives_addon();

	while (true) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_filled_circle(400, 300, 300, al_map_rgb(255, 50, 50));
		al_flip_display();
	}

	return 0;
}