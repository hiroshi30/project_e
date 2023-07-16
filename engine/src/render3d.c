#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"

#include "render2d.h"

#include "camera.h"

#include "set.h"
#include "mesh.h"

#include "render3d.h"

#define POLYGONS_MAX_COUNT 1000

extern int WINDOW_HEIGHT, WINDOW_WIDTH;
extern SDL_Renderer *RENDERER;
extern int R, G, B, A;


void perspective_projection(Camera *camera, Mesh *mesh, Vector3* light, double delta_time) {
	Vector3* light = (Vector3 *)malloc(sizeof(Vector3));
	light->x = -1;
	light->y = -1;
	light->z = 1;
	Vector3_normalize(light, light);

	double r = 230, g = 20, b = 13;

	Vector3 *light2 = (Vector3 *)malloc(sizeof(Vector3));
	Vector4 *normal = (Vector4 *)malloc(sizeof(Vector4));

	delta_time = 0;

	Matrix *rot_x = Matrix_rotate_x_construct(10);
	Matrix *rot_y = Matrix_rotate_y_construct(180 + delta_time * 15);
	Matrix *scale = Matrix_scale_construct(2, 2, 2);
	Matrix *translate = Matrix_translate_construct(0, 0, 5);

	Vector4 ***triangle = (Vector4 ***)malloc(sizeof(Vector4 **) * POLYGONS_MAX_COUNT);
	for (int i = 0; i < POLYGONS_MAX_COUNT; ++i) {
		Vector4 **triangle[i] = (Vector4 **)malloc(sizeof(Vector4 *) * 3);
		for (int j = 0; j < 3; ++j)
			triangle[i][j] = (Vector4 *)malloc(sizeof(Vector4));
	}

    SDL_Vertex polygon[3];

	double k;

	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {

			Vector3_to_Vector4(mesh->norms[i][j], normal);

			Matrix_multiplication_Vector4(rot_x, normal, normal);
			Matrix_multiplication_Vector4(rot_y, normal, normal);

			light2->x = light->x + normal->x;
			light2->y = light->y + normal->y;
			light2->z = light->z + normal->z;
			k = fmax(0.3, sqrt(light2->x * light2->x + light2->y * light2->y + light2->z * light2->z) / 2);

			Vector3_multiplication_scalar(color, k, color2);

			Vector3_to_Vector4(mesh->verts[i][j], triangle[j]);

			Matrix_multiplication_Vector4(rot_x, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(rot_y, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(scale, triangle[j], triangle[j]);
			Matrix_multiplication_Vector4(translate, triangle[j], triangle[j]);

			Matrix_multiplication_Vector4(camera->matrix, triangle[j], triangle[j]);
			Vector4_normalize(triangle[j], triangle[j]);

			triangle[j]->x = (triangle[j]->x + 1) / 2 * WINDOW_WIDTH;
			triangle[j]->y = (triangle[j]->y + 1) / 2 * WINDOW_HEIGHT;

	        polygon[j] = (SDL_Vertex){
	        	{triangle[j]->x, WINDOW_HEIGHT - triangle[j]->y},
	        	{k * r, k * g, k * b, 255},
	    	    {0, 0}
	    	};
	    }
	   	SDL_RenderGeometry(RENDERER, NULL, polygon, 3, NULL, 0);
		// draw_polygon_mesh(triangle);
	}

	free(normal);
	free(light);
	free(light2);
	Matrix_destruct(rot_x);
	Matrix_destruct(rot_y);
	Matrix_destruct(scale); 
	Matrix_destruct(translate);

	for (int i = 0; i < 3; ++i)
		free(triangle[i]);
	free(triangle);
}