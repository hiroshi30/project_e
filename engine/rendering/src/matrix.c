#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

#define PI 3.14159
#define sin_d(x) sin(PI / 180 * x)
#define cos_d(x) cos(PI / 180 * x)


Matrix *Matrix_construct(int height, int width, double a[]) {
	Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
	matrix->height = height;
	matrix->width = width;
	matrix->a = (double **)malloc(sizeof(double *) * height);
	for (int i = 0; i < height; ++i) {
		matrix->a[i] = (double *)malloc(sizeof(double) * width);
		for (int j = 0; j < width; ++j) {
			matrix->a[i][j] = a[i * width + j];
		}
	}
	return matrix;
}

void Matrix_destruct(Matrix *matrix) {
	for (int i = 0; i < matrix->height; ++i) {
		free(matrix->a[i]);
	}
	free(matrix->a);
	free(matrix);
}

void Matrix_print(Matrix *matrix) {
	printf("Matrix {\n");

	for (int i = 0; i < matrix->height; ++i) {
		printf("    {");
		for (int j = 0; j < matrix->width; ++j) {
			if (j < matrix->width - 1) {
				printf("%lf, ", matrix->a[i][j]);	
			} else {
				printf("%lf", matrix->a[i][j]);
			}
		}
		if (i < matrix->height - 1) {
			printf("},\n");	
		} else {
			printf("}\n");
		}
	}

	printf("}\n");
}


Matrix *Matrix_rotate_x_construct(double degree) {
	Matrix *matrix = Matrix_construct(4, 4, (double []){
		1, 0, 0, 0,
		0, cos_d(degree), -sin_d(degree), 0,
		0, sin_d(degree), cos_d(degree), 0,
		0, 0, 0, 1 
	});
	return matrix;
}

Matrix *Matrix_rotate_y_construct(double degree) {
	Matrix *matrix = Matrix_construct(4, 4, (double []){
		cos_d(degree), 0, sin_d(degree), 0,
		0, 1, 0, 0,
		-sin_d(degree), 0, cos_d(degree), 0,
		0, 0, 0, 1 
	});
	return matrix;
}

Matrix *Matrix_rotate_z_construct(double degree) {
	Matrix *matrix = Matrix_construct(4, 4, (double []){
		cos_d(degree), -sin_d(degree), 0, 0,
		sin_d(degree), cos_d(degree), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	});
	return matrix;
}

Matrix *Matrix_scale_construct(double x, double y, double z) {
	Matrix *matrix = Matrix_construct(4, 4, (double []){
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	});
	return matrix;
}

Matrix *Matrix_translate_construct(double x, double y, double z) {
	Matrix *matrix = Matrix_construct(4, 4, (double []){
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	});
	return matrix;
}


void Matrix_summation(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix3->a[i][j] = matrix1->a[i][j] + matrix2->a[i][j];
		}
	}
}

void Matrix_summation_scalar(Matrix *matrix1, double scalar, Matrix *matrix2) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix2->a[i][j] = matrix1->a[i][j] + scalar;
		}
	}
}

void Matrix_subtracting(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix3->a[i][j] = matrix1->a[i][j] - matrix2->a[i][j];
		}
	}
}

void Matrix_subtracting_scalar(Matrix *matrix1, double scalar, Matrix *matrix2) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix2->a[i][j] = matrix1->a[i][j] - scalar;
		}
	}
}

void Matrix_multiplication(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3) {
	double a[matrix3->height * matrix3->width];
	for (int i = 0; i < matrix3->height; ++i) {
		for (int j = 0; j < matrix3->width; ++j) {
			a[i * matrix3->width + j] = 0;
		}
	}
	Matrix *matrix = Matrix_construct(matrix3->height, matrix3->width, a);
	
	for (int i = 0; i < matrix3->height; ++i) {
		for (int j = 0; j < matrix3->width; ++j) {
			for (int l = 0; l < matrix1->width; ++l) {
				matrix->a[i][j] += matrix1->a[i][l] * matrix2->a[l][j];
			}
		}
	}

	matrix3->a = matrix->a;
}

void Matrix_multiplication_scalar(Matrix *matrix1, double scalar, Matrix *matrix2) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix2->a[i][j] = matrix1->a[i][j] * scalar;
		}
	}
}

void Matrix_division_scalar(Matrix *matrix1, double scalar, Matrix *matrix2) {
	for (int i = 0; i < matrix1->height; ++i) {
		for (int j = 0; j < matrix1->width; ++j) {
			matrix2->a[i][j] = matrix1->a[i][j] / scalar;
		}
	}
}