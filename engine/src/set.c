#include <stdio.h>
#include <stdlib.h>

#include "vector3.h"
#include "set.h"


Set *Set_construct(int length, double a[]) {
	Set *set = (Set *)malloc(sizeof(Set));
	set->length = length;
	set->a = (Vector3 **)malloc(sizeof(Vector3 *) * length);
	for (int i = 0; i < length; ++i) {
		set->a[i] = (Vector3 *)malloc(sizeof(Vector3));
		set->a[i]->x = a[i * 3];
		set->a[i]->y = a[i * 3 + 1];
		set->a[i]->z = a[i * 3 + 2];
	}
	return set;
}

void Set_destruct(Set *set) {
	for (int i = 0; i < set->length; ++i) {
		free(set->a[i]);
	}
	free(set->a);
	free(set);
}

void Set_print(Set *set) {
	printf("Set {\n");
	for (int i = 0; i < set->length; ++i) {
		printf("    %d: {%lf, %lf, %lf", i, set->a[i]->x, set->a[i]->y, set->a[i]->z);
		if (i < set->length - 1) {
			printf("},\n");
		} else {
			printf("}\n");
		}
	}
	printf("}\n");
}