#include <stdbool.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "camera.h"

#include "vertices.h"
#include "mesh.h"

#include "render3d.h"

#define window_width 16 * 70
#define window_height 9 * 70


int main(void) {

	Engine_init(window_width, window_height);

	Camera *camera = Camera_construct(
		0.1, 1,     // near, far
		0, 1,       // left, right
		0, 1        // bottom, top
	);

	Vertices *vertices = Vertices_construct(8, (double []){
		0.1, 0.1, 0.1,
		0.1, 0.9, 0.1,
		0.9, 0.9, 0.1,
		0.9, 0.1, 0.1,

		0.1, 0.1, 0.9,
		0.1, 0.9, 0.9,
		0.9, 0.9, 0.9,
		0.9, 0.1, 0.9
	});

	Mesh *mesh = Mesh_construct(vertices, 12, (int []) {
		// near
		0, 1, 2,
		0, 2, 3,
		// far
		4, 5, 6,
		4, 6, 7,
		// left
		4, 5, 1,
		4, 1, 0,
		// right
		3, 2, 6,
		2, 6, 7,
		// bottom
		0, 4, 7,
		0, 7, 3,
		// top
		1, 5, 6,
		1, 6, 2
	});

	perspective_projection(camera, mesh);
	Engine_update();

	bool go = true;

	while (go) {
		while (Engine_event_status()) {
			go = Engine_event_exit();
		}
	}

	Mesh_destruct(mesh);
	Vertices_destruct(vertices);
	Camera_destruct(camera);
	Engine_exit();

	return 0;
}