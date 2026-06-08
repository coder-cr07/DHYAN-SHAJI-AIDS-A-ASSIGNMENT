#include <stdio.h>
#include <stdlib.h>

#define W 60
#define H 20
#define MAX 100

typedef struct { int type; int p[6]; } Obj;

static char canvas[H][W];
static Obj objs[MAX];
static int count;
static const char *names[] = {"Circle", "Rectangle", "Line", "Triangle"};
static const int npar[] = {3, 4, 4, 6};

static void clear_canvas(void) {
    int r, c;
    for (r = 0; r < H; r++)
        for (c = 0; c < W; c++)
            canvas[r][c] = '_';
}

static void set_pixel(int x, int y) {
    if (x >= 0 && x < W && y >= 0 && y < H)
        canvas[y][x] = '*';
    }

    static void draw_line(int x1, int y1, int x2, int y2) {
        int dx = abs(x2 - x1), dy = abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1;
        int err = dx - dy, x = x1, y = y1, e2;
        while (1) {
            set_pixel(x, y);
            if (x == x2 && y == y2) break;
            e2 = 2 * err;
            if (e2 > -dy) { err -= dy; x += sx; }
            if (e2 < dx)  { err += dx; y += sy; }
        }
    }
    

