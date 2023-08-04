typedef struct Camera {
	double near;
	double far;
	double fov;
	Matrix *matrix;
	Vector3 *pos;
	Vector3 *look_at;
} Camera;

Camera *Camera_construct(double near, double far, double fov);
void Camera_destruct(Camera *camera);