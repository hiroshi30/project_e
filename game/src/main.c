#include "engine.h"

#define window_width 16 * 75
#define window_height 9 * 75


int main(void) {

	Engine_init(window_width, window_height, "project_e");

	Camera *camera = Camera_construct(
		// near, far, fov
		0.1, 1000, 90
	);

	Mesh *mesh = obj_read("C:/Users/takayama/Desktop/project_e/game/models/obj/monkey.obj");
	Mesh_rotate_x(mesh, 10);
	Mesh_rotate_y(mesh, 180);
	Mesh_scale(mesh, 2, 2, 2);
	Mesh_translate(mesh, 0, 0, 5);

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
		
		Mesh_translate(mesh, 0, 0, -5);
		Mesh_rotate_y(mesh, delta_time * 15);
		Mesh_translate(mesh, 0, 0, 5);

		mingw_gettimeofday(&t1, NULL);

		perspective_projection(camera, mesh);
		set_color(255, 255, 255);
		draw_line(100, 500, 80, 10);

		Engine_update();
	}

	Mesh_destruct(mesh);
	Camera_destruct(camera);
	Engine_exit();

	return 0;
}