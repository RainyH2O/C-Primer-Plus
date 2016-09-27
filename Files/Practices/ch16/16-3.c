#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD ((4 * atan(1)) / 180)

struct pos {
    double x;
    double y;
};

struct pos transpos(struct pos);

int main(void)
{
    struct pos polar;
    struct pos rect;

    printf("Enter position: ");
    scanf("%lf %lf", &polar.x, &polar.y);
    rect = transpos(polar);
    printf("Polar: %f %f\n", polar.x, polar.y);
    printf("Rect: %f %f\n", rect.x, rect.y);

    return 0;
}

struct pos transpos(struct pos p)
{
    struct pos r;
    double ang = p.y * DEG_TO_RAD;

    r.x = p.x * cos(ang);
    r.y = p.x * sin(ang);

    return r;
}
