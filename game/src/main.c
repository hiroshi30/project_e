#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "set.h"
#include "mesh.h"
#include "camera.h"

#include "obj_reader.h"

#include "render3d.h"

#define window_width 16 * 75
#define window_height 9 * 75


int main(void) {

	Engine_init(window_width, window_height, "project_e");

	Camera *camera = Camera_construct(
		// near, far, fov
		0.1, 1000, 90
	);

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
	Camera_destruct(camera);
	Engine_exit();

	return 0;
}