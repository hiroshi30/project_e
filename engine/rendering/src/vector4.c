#include <stdio.h>
#include <math.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"


void Vector4_print(Vector4 *vect) {
	printf("Vector4 {\n");
	printf("    %lf,\n", vect->x);
	printf("    %lf,\n", vect->y);
	printf("    %lf,\n", vect->z);
	printf("    %lf\n", vect->w);
	printf("}\n");
}


void Vector4_summation(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3) {
	vect3->x = vect1->x + vect2->x;
	vect3->y = vect1->y + vect2->y;
	vect3->z = vect1->z + vect2->z;
	vect3->w = vect1->w + vect2->w;
}

void Vector4_summation_scalar(Vector4 *vect1, double scalar, Vector4 *vect2) {
	vect2->x = vect1->x + scalar;
	vect2->y = vect1->y + scalar;
	vect2->z = vect1->z + scalar;
	vect2->w = vect1->w + scalar;
}

void Vector4_subtracting(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3) {
	vect3->x = vect1->x - vect2->x;
	vect3->y = vect1->y - vect2->y;
	vect3->z = vect1->z - vect2->z;
	vect3->w = vect1->w - vect2->w;
}

void Vector4_subtracting_scalar(Vector4 *vect1, double scalar, Vector4 *vect2) {
	vect2->x = vect1->x - scalar;
	vect2->y = vect1->y - scalar;
	vect2->z = vect1->z - scalar;
	vect2->w = vect1->w - scalar;
}

void Vector4_inverting(Vector4 *vect1, Vector4 *vect2) {
	vect2->x = -vect1->x;
	vect2->y = -vect1->y;
	vect2->z = -vect1->z;
	vect2->w = -vect1->w;
}


double Vector4_square_length(Vector4 *vect) {
	return vect->x * vect->x + vect->y * vect->y + vect->z * vect->z;
}

double Vector4_length(Vector4 *vect) {
	return sqrt(Vector4_square_length(vect));
}

void Vector4_normalize(Vector4 *vect1, Vector4 *vect2) {
	if (vect1->w != 1 && vect1->w != 0) {
		vect2->x = vect1->x / vect1->w;
		vect2->y = vect1->y / vect1->w;
		vect2->z = vect1->z / vect1->w;
		vect2->w = 1;
	}
}

void Vector4_nn(Vector4 *vect1, Vector4 *vect2) {
	double length = sqrt(vect1->x * vect1->x + vect1->y * vect1->y + vect1->z * vect1->z);
	vect2->x = vect1->x / length;
	vect2->y = vect1->y / length;
	vect2->z = vect1->z / length;
	vect2->w = 1;
}

void Matrix_multiplication_Vector4(Matrix *matrix, Vector4 *vect1, Vector4 *vect2) {
	double x, y, z, w;
	x = matrix->a[0][0] * vect1->x + matrix->a[0][1] * vect1->y + matrix->a[0][2] * vect1->z + matrix->a[0][3] * vect1->w;
	y = matrix->a[1][0] * vect1->x + matrix->a[1][1] * vect1->y + matrix->a[1][2] * vect1->z + matrix->a[1][3] * vect1->w;
	z = matrix->a[2][0] * vect1->x + matrix->a[2][1] * vect1->y + matrix->a[2][2] * vect1->z + matrix->a[2][3] * vect1->w;
	w = matrix->a[3][0] * vect1->x + matrix->a[3][1] * vect1->y + matrix->a[3][2] * vect1->z + matrix->a[3][3] * vect1->w;
	vect2->x = x;
	vect2->y = y;
	vect2->z = z;
	vect2->w = w;
}

void Vector3_to_Vector4(Vector3 *vect1, Vector4 *vect2) {
	vect2->x = vect1->x;
	vect2->y = vect1->y;
	vect2->z = vect1->z;
	vect2->w = 1;
}

void Vector4_to_Vector3(Vector4 *vect1, Vector3 *vect2) {
	vect2->x = vect1->x / vect1->w;
	vect2->y = vect1->y / vect1->w;
	vect2->z = vect1->z / vect1->w;
}