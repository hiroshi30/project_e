#include "matrix.h"
#include "vector3.h"
#include "vector4.h"
#include "render2d.h"

#define window_width 16 * 70
#define window_height 9 * 70


int main(void) {

	Engine_init(window_width, window_height);

	bool go = true;

	while (go) {
		while (Engine_event_status()) {
			go = Engine_event_exit();
		}
		set_color(0, 0, 0);
		fill();
		set_color(255, 120, 0);
		draw_line(0, 0, 600, 200);
		Engine_update();
	}

	Engine_exit();

	return 0;
}