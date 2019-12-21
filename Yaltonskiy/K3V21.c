#include <stdio.h>
#include <math.h>

float func(float a, float b)
{
    float c;
    c = sqrt((a + 1)/(b+(3/2)));
    return c;
}

int main()
{
    float c;
    printf("x\t y\t f(x,y)\t\n");
    for(float x=0;x<=1.0;x+=0.1)
    {
        for(float y=-3.0;y<=3;y+=0.5) 
        {
            printf("%.3f  %.3f   %.3f\n", x, y, func(x,y));
        }
    }
    return 0;
}  