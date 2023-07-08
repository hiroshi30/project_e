#pragma once


typedef struct Vector3 {
	double x, y, z;
} Vector3;


void Vector3_print(Vector3 *vect);


void Vector3_summation(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3);
void Vector3_summation_scalar(Vector3 *vect1, double scalar, Vector3 *vect3);
void Vector3_subtracting(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3);
void Vector3_subtracting_scalar(Vector3 *vect1, double scalar, Vector3 *vect3);
void Vector3_inverting(Vector3 *vect1, Vector3 *vect3);


double Vector3_square_length(Vector3 *vect1);
double Vector3_length(Vector3 *vect1);
void Vector3_normalize(Vector3 *vect1, Vector3 *vect3);
double Vector3_dot(Vector3 *vect1, Vector3 *vect2);
double Vector3_cos(Vector3 *vect1, Vector3 *vect2);
void Vector3_cross(Vector3 *vect1, Vector3 *vect2, Vector3 *vect3);