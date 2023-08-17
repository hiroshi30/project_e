typedef struct Mesh {
	int length;
	Vector3 ***verts;
	Vector3 ***norms;
} Mesh;

Mesh *Mesh_construct(Set *vertices, Set *normals, int length, int a[], int b[]);
void Mesh_destruct(Mesh *mesh);

void Mesh_rotate_x(Mesh *mesh, double degree);
void Mesh_rotate_y(Mesh *mesh, double degree);
void Mesh_rotate_z(Mesh *mesh, double degree);
void Mesh_scale(Mesh *mesh, double x, double y, double z);
void Mesh_translate(Mesh *mesh, double x, double y, double z);