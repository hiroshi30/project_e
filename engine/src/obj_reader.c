#include <stdio.h>
#include <string.h>

#include "vector3.h"

#include "set.h"
#include "mesh.h"

#include "obj_reader.h"


Mesh *obj_read(char name[]) {
	FILE *file;
	file = fopen(name, "r");

	int vertices_count = 0;
	int normals_count = 0;
	int textures_count = 0;
	int polygons_count = 0;
	char c;

	while(true) {
		c = getc(file);
		// comments
		if (c == '#') {
			while (getc(file) != '\n') {}
		// mtl files names
		} else if (c == 'm') {
			while (getc(file) != '\n') {}
		// name of model
		} else if (c == 'o') {
			while (getc(file) != '\n') {}
		} else if (c == 'v') {
			c = getc(file);
			// coords of vertices 
			if (c == ' ') {
				++vertices_count;
				while (getc(file) != '\n') {}
			// coords of normals
			} else if (c == 'n') {
				++normals_count;
				while (getc(file) != '\n') {}
			// coords of textures 
			} else if (c == 't') {
				++textures_count;
				while (getc(file) != '\n') {}			
			}
		// i dont know
		} else if (c == 's') {
			while (getc(file) != '\n') {}
		// what mtl style to use
		} else if (c == 'u') {
			while (getc(file) != '\n') {}
		// numbers of coordinates, textures and normals what to use for polygon
		} else if (c == 'f') {
			++polygons_count;
			while (getc(file) != '\n') {}
		} else {break;}
	}

	rewind(file);

	double verts[vertices_count * 3];
	double norms[normals_count * 3];
	double texs[textures_count * 2];
	int polygons_verts[polygons_count * 3];
	int polygons_norms[polygons_count * 3];
	int polygons_texs[polygons_count * 3];

	int vertices_index = 0;
	int normals_index = 0;
	int textures_index = 0;
	int polygons_index = 0;

	while(true) {
		c = getc(file);
		if (c == '#') {
			while (getc(file) != '\n') {}
		} else if (c == 'm') {
			while (getc(file) != '\n') {}
		} else if (c == 'o') {
			while (getc(file) != '\n') {}
		} else if (c == 'v') {
			c = getc(file);
			if (c == ' ') {
				for (int i = 0; i < 3; ++i) {
					fscanf(file, "%lf", &verts[vertices_index * 3 + i]);
				}
				++vertices_index;
				while (getc(file) != '\n') {}
			} else if (c == 'n') {
				for (int i = 0; i < 3; ++i) {
					fscanf(file, "%lf", &norms[normals_index * 3 + i]);
				}
				++normals_index;
				while (getc(file) != '\n') {}
			} else if (c == 't') {
				for (int i = 0; i < 2; ++i) {
					fscanf(file, "%lf", &texs[textures_index * 2 + i]);
				}
				++textures_index;
				while (getc(file) != '\n') {}
			}
		} else if (c == 's') {
			while (getc(file) != '\n') {}
		} else if (c == 'u') {
			while (getc(file) != '\n') {}
		} else if (c == 'f') {
			for (int i = 0; i < 3; ++i) {
				fscanf(file, "%d", &polygons_verts[polygons_index * 3 + i]);
				getc(file);
				fscanf(file, "%d", &polygons_texs[polygons_index * 3 + i]);
				getc(file);
				fscanf(file, "%d", &polygons_norms[polygons_index * 3 + i]);
			}
			++polygons_index;
			while (getc(file) != '\n') {}
		} else {break;}
	}

	Set *vertices = Set_construct(vertices_count, verts);
	Set *normals = Set_construct(normals_count, norms);
	Mesh *mesh = Mesh_construct(vertices, normals, polygons_count, polygons_verts, polygons_norms);

	Set_destruct(vertices);
	Set_destruct(normals);
	fclose(file);

	return mesh;
}