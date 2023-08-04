#include "engine.h"

#define window_width 16 * 75
#define window_height 9 * 75


int main(void) {

	Engine_init(window_width, window_height, "project_e");

	Camera *camera = Camera_construct(
		// near, far, fov
		0.1, 1000, 90
	);

	Z_BUFFER_construct();

	Mesh *mesh = obj_read("C:/Users/takayama/Desktop/project_e/models/obj/monkey.obj");

	struct timeval t1, t2;
	mingw_gettimeofday(&t1, NULL);
	double delta_time;

	bool go = true;

	while (go) {
		while (Engine_event_status()) {
			go = Engine_event_exit();
		}

		set_color(0, 0, 0);
		fill();

		mingw_gettimeofday(&t2, NULL);
		delta_time = (double)(t2.tv_usec - t1.tv_usec) / 1000000 + (double)(t2.tv_sec - t1.tv_sec);
		
		perspective_projection(camera, mesh, delta_time);
		Engine_update();
	}

	Mesh_destruct(mesh);
	Z_BUFFER_destruct();
	Camera_destruct(camera);
	Engine_exit();

	return 0;
}