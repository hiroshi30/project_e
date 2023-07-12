#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vector3.h"


void Vector3_print(Vector3 *vect) {
	printf("Vector3 {\n");
	printf("    %lf,\n", vect->x);
	printf("    %lf,\n", vect->y);
	printf("    %lf\n", vect->z);
	printf("}\n");
}


void Vector3_summation(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3) {
	vect3->x = vect1->x + vect2->x;
	vect3->y = vect1->y + vect2->y;
	vect3->z = vect1->z + vect2->z;
}

void Vector3_summation_scalar(Vector3 *vect1, double scalar, Vector3 *vect2) {
	vect2->x = vect1->x + scalar;
	vect2->y = vect1->y + scalar;
	vect2->z = vect1->z + scalar;
}

void Vector3_subtracting(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3) {
	vect3->x = vect1->x - vect2->x;
	vect3->y = vect1->y - vect2->y;
	vect3->z = vect1->z - vect2->z;
}

void Vector3_subtracting_scalar(Vector3 *vect1, double scalar, Vector3 *vect2) {
	vect2->x = vect1->x - scalar;
	vect2->y = vect1->y - scalar;
	vect2->z = vect1->z - scalar;
}

void Vector3_inverting(Vector3 *vect1, Vector3 *vect2) {
	vect2->x = -vect1->x;
	vect2->y = -vect1->y;
	vect2->z = -vect1->z;
}


double Vector3_square_length(Vector3 *vect) {
	return vect->x * vect->x + vect->y * vect->y + vect->z * vect->z;
}

double Vector3_length(Vector3 *vect) {
	return sqrt(Vector3_square_length(vect));
}

void Vector3_normalize(Vector3 *vect1, Vector3 *vect2) {
	double length = Vector3_length(vect1);
	vect2->x = vect1->x / length;
	vect2->y = vect1->y / length;
	vect2->z = vect1->z / length;
}

double Vector3_dot(Vector3 *vect1, Vector3 *vect2) {
	return vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z;
}

double Vector3_cos(Vector3 *vect1, Vector3 *vect2) {
	return Vector3_dot(vect1, vect2) / sqrt(Vector3_square_length(vect1) * Vector3_square_length(vect2));
}

void Vector3_cross(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3) {
	double x, y, z;
	x = vect1->y * vect2->z - vect1->z * vect2->y;
	y = vect1->z * vect2->x - vect1->x * vect2->z;
	z = vect1->x * vect2->y - vect1->y * vect2->x;
	vect3->x = x;
	vect3->y = y;
	vect3->z = z;
}