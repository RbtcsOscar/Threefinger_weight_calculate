#define _crt_secure_no_warnings
#include <stdio.h>
#include <math.h>

#define PI 3.141592

typedef struct matrix {
    double m[3][3];
    double v[3];
}Matrix;

Matrix rotate(double theta)
{
    double th = PI * theta / 180.0;
    double c = cos(th);
    double s = sin(th);

    Matrix r = { 
        {
        {c,-s,0},
        {s,c,0},
        {0,0,1}
        } 
    };
    return r;
}
double cal_weight(double f1[], double f2[], double f3[])
{
    int i,j;
    double result = 0;
    Matrix R1, R2, R3;


    R1 = rotate(-150);
    R2 = rotate(90);
    R3 = rotate(-30);

    double f_vector[3]={0,0,0};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            f_vector[i] += R1.m[i][j] * f1[j];
            f_vector[i] += R2.m[i][j] * f2[j];
            f_vector[i] += R3.m[i][j] * f3[j];
        }

        printf("%f  ", f_vector[i]);
    }

    printf("\n");
    result = sqrt(pow(f_vector[0], 2) + pow(f_vector[1], 2) + pow(f_vector[2], 2));

    return result;
 
}
int main()
{
    double x[3] = { 814, -21, -41 };
    double y[3] = { 676, -41, -272 };
    double z[3] = { 752, 4, 4 };

    double result=cal_weight(x, y, z);


        printf("%f\n", result);



    return 0;
}