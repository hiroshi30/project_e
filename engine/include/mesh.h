typedef struct Mesh {
	int length;
	Vector3 ***verts;
	Vector3 ***norms;
} Mesh;

Mesh *Mesh_construct(Set *vertices, Set *normals, int length, int a[], int b[]);
void Mesh_destruct(Mesh *mesh);
void Mesh_print(Mesh *mesh);