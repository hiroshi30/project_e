#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "set.h"
#include "mesh.h"

#include "camera.h"

#include "render3d.h"

extern SDL_Renderer *RENDERER;
extern int WINDOW_HEIGHT, WINDOW_WIDTH;

double **Z_BUFFER;

void Z_BUFFER_construct(void) {
	Z_BUFFER = (double **)malloc(sizeof(double *) * WINDOW_HEIGHT);
	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
		Z_BUFFER[i] = (double *)malloc(sizeof(double) * WINDOW_WIDTH);
	}
}

void Z_BUFFER_destruct(void) {
	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
		free(Z_BUFFER[i]);
	}
	free(Z_BUFFER);
}

void Vector4_swap(Vector4 *vect1, Vector4 *vect2) {
	vect2->x = vect1->x;
	vect2->y = vect1->y;
	vect2->z = vect1->z;
	vect2->w = vect1->w;
}

void perspective_projection(Camera *camera, Mesh *mesh, double delta_time) {
	Matrix *rot_x = Matrix_rotate_x_construct(10);
	Matrix *rot_y = Matrix_rotate_y_construct(180 + delta_time * 15);
	Matrix *scale = Matrix_scale_construct(2, 2, 2);
	Matrix *translate = Matrix_translate_construct(0, 0, 5);

	Vector4 **triangle = (Vector4 **)malloc(sizeof(Vector4 *) * 3);
	for (int j = 0; j < 3; ++j) {
		triangle[j] = (Vector4 *)malloc(sizeof(Vector4));
	}

    SDL_Vertex polygon[3];
    double r = 201, g = 105, b = 83;

	double z_depth, x, y;

	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
		for (int j = 0; j < WINDOW_WIDTH; ++j) {
			Z_BUFFER[i][j] = camera->far;
		}
	}

	for (int i = 0; i < mesh->length; ++i) {
		z_depth = 0;
		x = 0;
		y = 0;

		for (int j = 0; j < 3; ++j) {

			Vector3_to_Vector4(mesh->verts[i][j], triangle[j]);

			Matrix_multiplication_Vector4(rot_x, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(rot_y, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(scale, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(translate, triangle[j], triangle[j]);

			z_depth += triangle[j]->z;

			Matrix_multiplication_Vector4(camera->matrix, triangle[j], triangle[j]);
			Vector4_normalize(triangle[j], triangle[j]);

			triangle[j]->x = (triangle[j]->x + 1) / 2 * WINDOW_WIDTH;
			triangle[j]->y = (triangle[j]->y + 1) / 2 * WINDOW_HEIGHT;
			
			x += triangle[j]->x;
			y += triangle[j]->y;

	        polygon[j] = (SDL_Vertex){
	        	{triangle[j]->x, WINDOW_HEIGHT - triangle[j]->y},
	        	{r * z_depth / 10, g, b, 255},
	    	    {0, 0}
	    	};
	    }

	    z_depth /= 3;
	    x /= 3;
	    y /= 3;

	    if (z_depth < Z_BUFFER[(int)y][(int)x]) {
	    	
		   	SDL_RenderGeometry(RENDERER, NULL, polygon, 3, NULL, 0);
			draw_polygon_mesh(triangle);
	    }
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