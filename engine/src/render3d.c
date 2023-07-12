#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "camera.h"

#include "vertices.h"
#include "mesh.h"

#include "render3d.h"


void perspective_projection(Camera *camera, Mesh *mesh) {
	set_color(0, 0, 0);
	fill();
	set_color(70, 255, 50);

	Vector4 **triangle = (Vector4 **)malloc(sizeof(Vector4 *) * 3);
	for (int i = 0; i < 3; ++i)
		triangle[i] = (Vector4 *)malloc(sizeof(Vector4));

	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
			Vector3_to_Vector4(mesh->a[i][j], triangle[j]);
			Matrix_multiplication_Vector4(camera->perspective_projection_matrix, triangle[j], triangle[j]);
			Vector4_normalize(triangle[j], triangle[j]);
		}

		// printf("triangle[0] ");
		// Vector4_print(triangle[0]);

		// printf("triangle[1] ");
		// Vector4_print(triangle[1]);

		// printf("triangle[2] ");
		// Vector4_print(triangle[2]);

		draw_polygon_mesh(triangle);
	}

	for (int i = 0; i < 3; ++i)
		free(triangle[i]);
	free(triangle);
}