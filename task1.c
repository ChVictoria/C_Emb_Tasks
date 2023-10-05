#include <stdio.h>
#include <math.h>

int main() {
    double a;

    printf("Input an angle:");
    int ret = scanf("%lf", &a);

    if(ret==1) {
        double z1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);
        double z2 = 2 * sqrt(2) * cos(a) * sin(M_PI / 4 + 2 * a);

        printf("z1 = %lf\nz2 = %lf\n", z1, z2);
    }
    else{
        printf("Error: incorrect input");
    }

    return 0;
}
