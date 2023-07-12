typedef struct Vertices {
	int length;
	Vector3 **a;
} Vertices;

Vertices *Vertices_construct(int length, double points[]);
void Vertices_destruct(Vertices *vertices);
void Vertices_print(Vertices *vertices);