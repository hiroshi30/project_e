#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vector3.h"
#include "set.h"
#include "mesh.h"

#define PI 3.14159
#define sin_d(x) sin(PI / 180 * x)
#define cos_d(x) cos(PI / 180 * x)


Mesh *Mesh_construct(Set *vertices, Set *normals, int length, int a[], int b[]) {
	Mesh *mesh = (Mesh *)malloc(sizeof(Mesh));
	mesh->length = length;
	
	mesh->verts = (Vector3 ***)malloc(sizeof(Vector3 **) * length);
	for (int i = 0; i < length; ++i) {
		mesh->verts[i] = (Vector3 **)malloc(sizeof(Vector3 *) * 3);
		for (int j = 0; j < 3; ++j) {
			mesh->verts[i][j] = (Vector3 *)malloc(sizeof(Vector3));
			mesh->verts[i][j]->x = vertices->a[a[i * 3 + j] - 1]->x;
			mesh->verts[i][j]->y = vertices->a[a[i * 3 + j] - 1]->y;
			mesh->verts[i][j]->z = vertices->a[a[i * 3 + j] - 1]->z;
		}
	}

	mesh->norms = (Vector3 ***)malloc(sizeof(Vector3 **) * length);
	for (int i = 0; i < length; ++i) {
		mesh->norms[i] = (Vector3 **)malloc(sizeof(Vector3 *) * 3);
		for (int j = 0; j < 3; ++j) {
			mesh->norms[i][j] = (Vector3 *)malloc(sizeof(Vector3));
			mesh->norms[i][j]->x = normals->a[b[i * 3 + j] - 1]->x;
			mesh->norms[i][j]->y = normals->a[b[i * 3 + j] - 1]->y;
			mesh->norms[i][j]->z = normals->a[b[i * 3 + j] - 1]->z;
		}
	}
	
	return mesh;
}

void Mesh_destruct(Mesh *mesh) {
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 0; ++j) {
			free(mesh->verts[i][j]);
			free(mesh->norms[i][j]);
		}
		free(mesh->verts[i]);
		free(mesh->norms[i]);
	}
	free(mesh->verts);
	free(mesh->norms);
	free(mesh);
}


void Mesh_rotate_x(Mesh *mesh, double degree) {
	double _sin, _cos;
	_sin = sin_d(degree);
	_cos = cos_d(degree);
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
			mesh->verts[i][j]->y = mesh->verts[i][j]->y * _cos + mesh->verts[i][j]->z * -_sin;
			mesh->verts[i][j]->z = mesh->verts[i][j]->y * _sin + mesh->verts[i][j]->z * _cos;

			mesh->norms[i][j]->y = mesh->norms[i][j]->y * _cos + mesh->norms[i][j]->z * -_sin;
			mesh->norms[i][j]->z = mesh->norms[i][j]->y * _sin + mesh->norms[i][j]->z * _cos;
		}
	}
}


void Mesh_rotate_y(Mesh *mesh, double degree) {
	double _sin, _cos;
	_sin = sin_d(degree);
	_cos = cos_d(degree);
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
			mesh->verts[i][j]->x = mesh->verts[i][j]->x * _cos + mesh->verts[i][j]->z * _sin;
			mesh->verts[i][j]->z = mesh->verts[i][j]->x * -_sin + mesh->verts[i][j]->z * _cos;

			mesh->norms[i][j]->x = mesh->norms[i][j]->x * _cos + mesh->norms[i][j]->z * _sin;
			mesh->norms[i][j]->z = mesh->norms[i][j]->x * -_sin + mesh->norms[i][j]->z * _cos;
		}
	}
}


void Mesh_rotate_z(Mesh *mesh, double degree) {
	double _sin, _cos;
	_sin = sin_d(degree);
	_cos = cos_d(degree);
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
				mesh->verts[i][j]->x = mesh->verts[i][j]->x * _cos + mesh->verts[i][j]->y * -_sin;
				mesh->verts[i][j]->y = mesh->verts[i][j]->x * _sin + mesh->verts[i][j]->y * _cos;

				mesh->norms[i][j]->x = mesh->norms[i][j]->x * _cos + mesh->norms[i][j]->y * -_sin;
				mesh->norms[i][j]->y = mesh->norms[i][j]->x * _sin + mesh->norms[i][j]->y * _cos;
		}
	}
}

void Mesh_scale(Mesh *mesh, double x, double y, double z) {
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
			mesh->verts[i][j]->x *= x;
			mesh->verts[i][j]->y *= y;
			mesh->verts[i][j]->z *= z;
		}
	}
}

void Mesh_translate(Mesh *mesh, double x, double y, double z) {
	for (int i = 0; i < mesh->length; ++i) {
		for (int j = 0; j < 3; ++j) {
			mesh->verts[i][j]->x += x;
			mesh->verts[i][j]->y += y;
			mesh->verts[i][j]->z += z;
		}
	}
}