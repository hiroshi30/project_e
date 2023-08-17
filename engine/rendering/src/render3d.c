#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>

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

// double z_buffer[WINDOW_HEIGHT][WINDOW_WIDTH];

void perspective_projection(Camera *camera, Mesh *mesh) {

	Vector3 *light = (Vector3 *)malloc(sizeof(Vector3));
	light->x = 0;
	light->y = 0;
	light->z = 1;

	Vector3_normalize(light, light);

	double k;

	Vector4 **triangle = (Vector4 **)malloc(sizeof(Vector4 *) * 3);
	for (int j = 0; j < 3; ++j) {
		triangle[j] = (Vector4 *)malloc(sizeof(Vector4));
	}

    // SDL_Vertex polygon[3];
    // double r = 201, g = 105, b = 83;

    set_color(255, 255, 255);

	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {

			Vector3_to_Vector4(mesh->verts[i][j], triangle[j]);

			Matrix_multiplication_Vector4(camera->matrix, triangle[j], triangle[j]);
			Vector4_normalize(triangle[j], triangle[j]);

			triangle[j]->x = (triangle[j]->x + 1) / 2 * WINDOW_WIDTH;
			triangle[j]->y = (triangle[j]->y + 1) / 2 * WINDOW_HEIGHT;

			k = sqrt((light->x - mesh->norms[i][j]->x) * (light->x - mesh->norms[i][j]->x) + (light->y - mesh->norms[i][j]->y) * (light->y - mesh->norms[i][j]->y) + (light->z - mesh->norms[i][j]->z) * (light->z - mesh->norms[i][j]->z));
			k /= 2;

	        // polygon[j] = (SDL_Vertex){
	        // 	{triangle[j]->x, WINDOW_HEIGHT - triangle[j]->y},
	        // 	{k * 255, k * 255, k * 255, 255},
	    	//     {0, 0}
	    	// };
	    }

	   	// SDL_RenderGeometry(RENDERER, NULL, polygon, 3, NULL, 0);
		draw_polygon_mesh(triangle);
	}

	free(light);

	for (int j = 0; j < 3; ++j) {
		free(triangle[j]);
	}
	free(triangle);
}