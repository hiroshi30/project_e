#include <stdio.h>
#include <stdlib.h>

#include "vector3.h"
#include "vertices.h"


Vertices *Vertices_construct(int length, double points[]) {
	Vertices *vertices = (Vertices *)malloc(sizeof(Vertices));
	vertices->length = length;
	vertices->a = (Vector3 **)malloc(sizeof(Vector3 *) * length);
	for (int i = 0; i < length; ++i) {
		vertices->a[i] = (Vector3 *)malloc(sizeof(Vector3));
		vertices->a[i]->x = points[i * 3];
		vertices->a[i]->y = points[i * 3 + 1];
		vertices->a[i]->z = points[i * 3 + 2];
	}
	return vertices;
}

void Vertices_destruct(Vertices *vertices) {
	for (int i = 0; i < vertices->length; ++i) {
		free(vertices->a[i]);
	}
	free(vertices->a);
	free(vertices);
}

void Vertices_print(Vertices *vertices) {
	printf("Vertices\n");
	for (int i = 0; i < vertices->length; ++i) {
		printf("%d: {%lf, %lf, %lf}\n", i, vertices->a[i]->x, vertices->a[i]->y, vertices->a[i]->z);
	}
}