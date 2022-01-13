#include "stdio.h"
struct point
{
    float x;
    float y;
};

void setValues(const point a,point &b,point &c)
{
    c.x = b.x = a.x;
    c.y = b.y = a.y;
}

point middlePoint(const point *a,const point *b)
{
    point c;
    c.x = (a->x+b->x)*0.5;
    c.y = (a->y+b->y)*0.5;
    return c;
}

void printPoint(point a)
{
    printf("x: %f, y: %f\n",a.x,a.y);
}

int main()
{
    point a{1,2},b{3,4},c{5,6};
    printPoint(middlePoint(&b,&c));
    setValues(a,b,c);
    printPoint(b);
    printPoint(c);
}