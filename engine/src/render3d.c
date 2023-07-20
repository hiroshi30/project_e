#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "set.h"
#include "mesh.h"

#include "camera.h"

#include "render3d.h"

extern int WINDOW_HEIGHT, WINDOW_WIDTH;


void perspective_projection(Camera *camera, Mesh *mesh, double delta_time) {
	Matrix *rot_x = Matrix_rotate_x_construct(10);
	Matrix *rot_y = Matrix_rotate_y_construct(180 + delta_time * 15);
	Matrix *scale = Matrix_scale_construct(2, 2, 2);
	Matrix *translate = Matrix_translate_construct(0, 0, 5);

	Vector4 **triangle = (Vector4 **)malloc(sizeof(Vector4 *) * 3);
	for (int j = 0; j < 3; ++j) {
		triangle[j] = (Vector4 *)malloc(sizeof(Vector4));
	}

    // SDL_Vertex polygon[3];

	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {

			Vector3_to_Vector4(mesh->verts[i][j], triangle[j]);

			Matrix_multiplication_Vector4(rot_x, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(rot_y, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(scale, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(translate, triangle[j], triangle[j]);

			Matrix_multiplication_Vector4(camera->matrix, triangle[j], triangle[j]);
			Vector4_normalize(triangle[j], triangle[j]);

			triangle[j]->x = (triangle[j]->x + 1) / 2 * WINDOW_WIDTH;
			triangle[j]->y = (triangle[j]->y + 1) / 2 * WINDOW_HEIGHT;

	        // polygon[j] = (SDL_Vertex){
	        // 	{triangle[j]->x, WINDOW_HEIGHT - triangle[j]->y},
	        // 	{r, g, b, 255},
	    	//     {0, 0}
	    	// };
	    }
	   	// SDL_RenderGeometry(RENDERER, NULL, polygon, 3, NULL, 0);
		draw_polygon_mesh(triangle);
	}

	Matrix_destruct(rot_x);
	Matrix_destruct(rot_y);
	Matrix_destruct(scale);
	Matrix_destruct(translate);

	for (int j = 0; j < 3; ++j) {
		free(triangle[j]);
	}
	free(triangle);
}