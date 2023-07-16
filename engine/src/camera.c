#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
#include "vector3.h"
#include "camera.h"

#define PI 3.14159

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;


Camera *Camera_construct(double near, double far, double fov) {
	Camera *camera = (Camera *)malloc(sizeof(Camera));
	
	double a = (double)WINDOW_HEIGHT / (double)WINDOW_WIDTH;
	double f = 1 / tan(PI / 180 * (fov / 2));

	camera->matrix = Matrix_construct(4, 4, (double []) {
		a * f, 0, 0, 0,
		0, f, 0, 0,
		0, 0, far / (far - near), -far * near / (far - near),
		0, 0, 1, 0
	});

	// Matrix_print(camera->matrix);

	camera->pos = (Vector3 *)malloc(sizeof(Vector3));
	camera->pos->x = 0;
	camera->pos->y = 0;
	camera->pos->z = 0;

	camera->look_at = (Vector3 *)malloc(sizeof(Vector3));
	camera->look_at->x = 0;
	camera->look_at->y = 0;
	camera->look_at->z = 0;

	return camera;
}

void Camera_destruct(Camera *camera) {
	Matrix_destruct(camera->matrix);
	free(camera->pos);
	free(camera->look_at);
	free(camera);
}