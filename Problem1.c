#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main()
{
    double a, b, c, w, m;
    
    printf("Input first value for width of slit in micrometer: ");
    scanf("%lf", &a);
    
    printf("Input second value for width of slit in micrometer: ");
    scanf("%lf", &b);
    
    printf("Input third value for width of slit in micrometer: ");
    scanf("%lf", &c);

    printf("Input value for wavelength in nanometer (nm): ");
    scanf("%lf", &w);
    
    
    if (w < 380 || w > 750)
    {
        printf("Out of range. Please enter a valid number.\n");
        return 0;
    }

    printf("Input value for m: ");
    scanf("%lf", &m);

    
    w = w * 1e-9;  
    a = a * 1e-6;  
    b = b * 1e-6;
    c = c * 1e-6;

    double t1, t2, t3, ans1, ans2, ans3;

    
    t1 = (m * w) / a;
    t2 = (m * w) / b;
    t3 = (m * w) / c;

    if (fabs(t1) > 1 || fabs(t2) > 1 || fabs(t3) > 1)
    {
        printf("Invalid input: sin(θ) values exceed valid range. Try smaller m or larger slit widths.\n");
        return 0;
    }

    ans1 = asin(t1) * (180 / PI);  
    ans2 = asin(t2) * (180 / PI);
    ans3 = asin(t3) * (180 / PI);

    
    if (ans1 > ans2 && ans1 > ans3)
    {
        printf("Light bends the most when slit width is %.4lf\n", a * 1e6);
    }
    else if (ans2 > ans1 && ans2 > ans3)
    {
        printf("Light bends the most when slit width is %.4lf\n", b * 1e6);
    }
    else
    {
        printf("Light bends the most when slit width is %.4lf\n", c * 1e6);
    }

    printf("Angles (in degrees):\n1 = %.9lf \n2 = %.9lf\n3 = %.9lf\n", ans1, ans2, ans3);

    return 0;
}
