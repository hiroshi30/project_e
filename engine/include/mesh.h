typedef struct Mesh {
	int length;
	Vector3 ***a;
} Mesh;

Mesh *Mesh_construct(Vertices *vertices, int length, int points[]);
void Mesh_destruct(Mesh *mesh);
void Mesh_print(Mesh *mesh);