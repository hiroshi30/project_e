typedef struct Set {
	int length;
	Vector3 **a;
} Set;

Set *Set_construct(int length, double a[]);
void Set_destruct(Set *set);
void Set_print(Set *set);