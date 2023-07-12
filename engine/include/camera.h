typedef struct Camera {
	Matrix *perspective_projection_matrix;
	Vector3 *pos;
	Vector3 *look_at;
} Camera;

Camera *Camera_construct(double near, double far, double left, double right, double bottom, double top);
void Camera_destruct(Camera *camera);