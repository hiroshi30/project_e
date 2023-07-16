void Engine_init(int window_width, int window_height, char title[]);
void Engine_update(void);
bool Engine_event_status(void);
bool Engine_event_exit(void);
void Engine_exit(void);

void set_color(int r, int g, int b);
void set_transparency(int a);
void fill(void);
void draw_circle(double x, double y, double radius);
void draw_line(double x1, double y1, double x2, double y2);
void draw_polygon_mesh(Vector4 **triangle);