#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"


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
	for (int i = 0; i < matrix3->height; ++i) {
		for (int j = 0; j < matrix3->width; ++j) {
			matrix3->a[i][j] = 0;
		}
	}

	for (int i = 0; i < matrix3->height; ++i) {
		for (int j = 0; j < matrix3->width; ++j) {
			for (int l = 0; l < matrix1->width; ++l) {
				matrix3->a[i][j] += matrix1->a[i][l] * matrix2->a[l][j];
			}
		}
	}
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