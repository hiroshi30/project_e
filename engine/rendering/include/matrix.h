typedef struct Matrix {
	int height, width;
	double **a;
} Matrix;

Matrix *Matrix_construct(int height, int width, double a[]);
void Matrix_destruct(Matrix *matrix);
void Matrix_print(Matrix *matrix);

Matrix *Matrix_rotate_x_construct(double degree);
Matrix *Matrix_rotate_y_construct(double degree);
Matrix *Matrix_rotate_z_construct(double degree);
Matrix *Matrix_scale_construct(double x, double y, double z);
Matrix *Matrix_translate_construct(double x, double y, double z);

void Matrix_summation(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3);
void Matrix_summation_scalar(Matrix *matrix1, double scalar, Matrix *matrix2);
void Matrix_subtracting(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3);
void Matrix_subtracting_scalar(Matrix *matrix1, double scalar, Matrix *matrix2);
void Matrix_multiplication(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3);
void Matrix_multiplication_scalar(Matrix *matrix1, double scalar, Matrix *matrix2);
void Matrix_division_scalar(Matrix *matrix1, double scalar, Matrix *matrix2);