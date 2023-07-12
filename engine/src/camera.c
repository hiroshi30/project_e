#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "vector3.h"
#include "camera.h"


Camera *Camera_construct(double near, double far, double left, double right, double bottom, double top) {
	Camera *camera = (Camera *)malloc(sizeof(Camera));


	Matrix *perspective_matrix = Matrix_construct(4, 4, (double []){
		near, 0, 0, 0,
		0, near, 0, 0,
		0, 0, far + near, -far * near,
		0, 0, 1, 0
	});

	Matrix *ortographic_projection_matrix = Matrix_construct(4, 4, (double []){
		2 / (right - left), 0, 0, -(right + left) / (right - left),
		0, -2 / (bottom - top), 0, (bottom + top) / (bottom - top),
		0, 0, 1 / (far - near), -near / (far - near),
		0, 0, 0, 1
	});
	
	camera->perspective_projection_matrix = Matrix_construct(4, 4, (double []) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	});

	Matrix_multiplication(ortographic_projection_matrix, perspective_matrix, camera->perspective_projection_matrix);

	printf("perspective_projection_matrix ");
	Matrix_print(camera->perspective_projection_matrix);

	Matrix_destruct(perspective_matrix);
	Matrix_destruct(ortographic_projection_matrix);
	
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
	Matrix_destruct(camera->perspective_projection_matrix);
	free(camera->pos);
	free(camera->look_at);
	free(camera);
}