#include <stdbool.h>


void Engine_init(int window_width, int window_height);
void Engine_update(void);
bool Engine_event_status(void);
bool Engine_event_exit(void);
void Engine_exit(void);

void set_color(int r, int g, int b);
void fill(void);
void draw_circle(double x, double y, double radius);
void draw_line(double x1, double y1, double x2, double y2);