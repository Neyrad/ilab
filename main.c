#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double epsilon = 1e-8;

int is_zero(double a)
{
    return fabs(a) < epsilon;
}

void SolveLinear(double a, double b)
{
    if (is_zero(a) && !is_zero(b))
     printf("\tNo roots!\n");

    if (is_zero(a) && is_zero(b))
     printf("\tAny number is a root!\n");

    if (!is_zero(a) && !is_zero(b))
     printf("\tThere is only one root: x = %lg\n", -b / a);

    if (!is_zero(a) && is_zero(b))
     printf("\tThere is only one root: x = 0\n");
}

void SolveQuadratic(double a, double b, double c)
{
   if (!is_zero(a))
   {
        if ((b*b - 4*a*c) < 0)
            printf("\tNo roots!\n");

        if ((b*b - 4*a*c) > 0)
              {
                printf("\tThere are two roots: x = %lg\n\n", (-b - sqrt(b*b - 4*a*c))/(2*a));
                printf("\t                     x = %lg\n", (-b + sqrt(b*b - 4*a*c))/(2*a));
              }

        if (is_zero(b*b - 4*a*c))
              {
                if (is_zero(b))// prints 0 istead of -0
                printf("\tThere is only one root: x = 0\n");

                else
                printf("\tThere is only one root: x = %lg\n", -b / (2*a));
              }
   }

   else
   SolveLinear(b, c);
}

int main()
{
    double a = 0, b = 0, c = 0; // coeffs
    int i = 0; //iteration counter for do...while loop2

    printf("\n\tQuadraticSolver by AG, v. 1.2\n");
    printf("\n\tPlease, enter coeffs of a quadratic equation ax^2 + bx + c = 0\n\n");

    do
        {
            i++;

            if (i != 1) //if this is not the first iteration, prints error message
            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");

            printf ("                   a = ");
            scanf("%lg", &a);
            fflush(stdin);
            printf("\n");

        }  while (scanf("%lg", &a) != 1);

    i = 0;

    do
        {
            i++;

            if (i != 1) //if this is not the first iteration, prints error message
            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");

            printf ("                   b = ");
            scanf("%lg", &b);
            fflush(stdin);
            printf("\n");

        }  while (scanf("%lg", &b); != 1);

    i = 0;

    do
        {
            i++;

            if (i != 1) //if this is not the first iteration, prints error message
            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");

            printf ("                   c = ");
            scanf("%lg", &c);
            fflush(stdin);
            printf("\n");

        }  while (scanf("%lg", &c); != 1);

    i = 0;

    SolveQuadratic(a, b, c);
    printf("\n\tThat's it!\n\n\n");
    return 0;
}
