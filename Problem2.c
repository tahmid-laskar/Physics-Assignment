#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main() {

    int m_green = 3, m_red = 2;
    double lambda_green = 530e-9, lambda_red = 700e-9;
    double theta_green = 65.0;


    double d = (m_green * lambda_green) / sin(theta_green * (PI / 180.0));

    double sin_theta = (m_red * lambda_red) / d;
    double theta_red = sin_theta*(180.0 / PI);

    if (theta_red != -1) {
        printf("The second-order diffraction angle for red light is: %.2f degrees\n", theta_red);
    }

    return 0;
}
