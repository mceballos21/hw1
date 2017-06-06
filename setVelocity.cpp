#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#define MAX_PARTICLES 1000
#define GRAVITY 0.1


struct Vec { 
    float x, y, z;
};

struct Shape {
    float width, height;
    float radius;
    Vec center;
};

struct Particle {
    Shape s;
    Vec velocity;
};

struct Game {
    public:
	Shape box;
	Particle particle[MAX_PARTICLES];
	int n;
	Game(){
	    n=0;
	}
};

//Function prototypes
void initXWindows(void);
void init_opengl(void);
void cleanupXWindows(void);
void check_mouse(XEvent *e, Game *game);
int check_keys(XEvent *e, Game *game);
void movement(Game *game);
void render(Game *game);

#define rnd() (float)rand() / (float)RAND_MAX

void setVelocity(Particle *p) 
{
    p->velocity.y = rnd() * 2.0 - 1.0;
    p->velocity.x = rnd() * 2.0 - 1.0;
}
