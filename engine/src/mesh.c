#include <stdio.h>
#include <stdlib.h>

#include "vector3.h"
#include "vertices.h"
#include "mesh.h"


Mesh *Mesh_construct(Vertices *vertices, int length, int points[]) {
	Mesh *mesh = (Mesh *)malloc(sizeof(Mesh));
	mesh->length = length;
	mesh->a = (Vector3 ***)malloc(sizeof(Vector3 **) * length);
	for (int i = 0; i < length; ++i) {
		mesh->a[i] = (Vector3 **)malloc(sizeof(Vector3 *) * 3);
		for (int j = 0; j < 3; ++j) {
			mesh->a[i][j] = vertices->a[points[i * 3 + j]];
		}
	}
	return mesh;
}

void Mesh_destruct(Mesh *mesh) {
	for (int i = 0; i < mesh->length; ++i) {
		free(mesh->a[i]);
	}
	free(mesh->a);
	free(mesh);
}

void Mesh_print(Mesh *mesh) {
	printf("Mesh {\n");
	for (int i = 0; i < mesh->length; ++i) {
		printf("    %d: {\n", i);
		for (int j = 0; j < 3; ++j) {
			printf("        {%lf, %lf, %lf", mesh->a[i][j]->x, mesh->a[i][j]->y, mesh->a[i][j]->z);
			if (j < 3 - 1) {
				printf("},\n");
			} else {
				printf("}\n");
			}
		}
		if (i < mesh->length - 1) {
			printf("    },\n");
		} else {
			printf("    }\n");
		}
	}
	printf("}\n");
}