#include <stdio.h>

#include "matrix.h"
// #include "render2d.h"


int main(void) {
	Matrix *matrix1 = Matrix_construct(4, 5, (double []){
		2, -1, 0, 3, -4,
		3, -2, 2, 1, 0,
		-1, 3, -1, -2, -4,
		3, 3, -4, 2, -2
	});

	Matrix *matrix2 = Matrix_construct(5, 3, (double []){
		2, 2, 3,
		-2, -1, 2,
		3, 4, 1,
		-3, 4, 0,
		1, -3, 4
	});

	Matrix *matrix3 = Matrix_construct(4, 3, (double []){
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	});

	Matrix *result = Matrix_construct(4, 3, (double []){
	    -7.000000, 29.000000, -12.000000,
	    13.000000, 20.000000, 7.000000,
	    -9.000000, -5.000000, -14.000000,
	    -20.000000, 1.000000, 3.000000
	});

	Matrix_multiplication(matrix1, matrix2, matrix3);

	for (int i = 0; i < matrix3->height; ++i) {
		for (int j = 0; j < matrix3->width; ++j) {
			if (matrix3->a[i][j] != result->a[i][j]) {
				printf("ERROR IN Matrix_multiplication()\n");

				printf("matrix1 ");
				Matrix_print(matrix1);
				printf("matrix2 ");
				Matrix_print(matrix2);
				printf("matrix3 ");
				Matrix_print(matrix3);
				printf("result ");
				Matrix_print(result);

				i = matrix3->height;
				j = matrix3->width;
				break;
			}
		}
	}
	
	printf("Matrix_multiplication() test complete\n");

	Matrix_destruct(matrix1);
	Matrix_destruct(matrix2);
	Matrix_destruct(matrix3);
	Matrix_destruct(result);
}