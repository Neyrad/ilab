#include <stdio.h>
#include <stdlib.h>
#include <math.h>





void SolveLinear(double a, double b)
{

    if (a == 0 && b != 0)

     printf("No roots!\n");


    if (a == 0 && b == 0)

     printf("Any number is a root!\n");


    if (a != 0)

     {

       double AntiNegativeZero = -b / a;  // prints 0 istead of -0


       if (AntiNegativeZero == -0)

       printf("There is only one root: x = 0\n");

       else

        printf("There is only one root: x = %lg\n", -b / a);

     }

}







void SolveQuadratic(double a, double b, double c)
{
   if (a != 0)
   {

            if ((b*b - 4*a*c) < 0)

                  printf("No roots!\n");



            if ((b*b - 4*a*c) > 0)

              {


                  printf("There are two roots: x = %lg\n\n", (-b - sqrt(b*b - 4*a*c))/(2*a));

                  printf("                     x = %lg\n", (-b + sqrt(b*b - 4*a*c))/(2*a));


              }



            if ((b*b - 4*a*c) == 0)

              {

                  double AntiNegativeZero= -b / a;  // prints 0 istead of -0


                  if (AntiNegativeZero == -0)

                    printf("There is only one root: x = 0\n");

                  else

                    printf("There is only one root: x = %lg\n", -b/(2*a));


             }

   }


   else


   SolveLinear(b, c);


}





int main()
{
    double a = 0, b = 0, c = 0; // coeffs




    printf("\nQuadraticSolver by AG, v. 1.0\n");
    printf("\nPlease, enter coeffs of a quadratic equation ax^2 + bx + c = 0\n\n");




    printf ("                   a = ");

    scanf("%lg", &a);





    printf("\n");





    printf ("                   b = ");

    scanf("%lg", &b);




    printf("\n");






    printf ("                   c = ");

    scanf("%lg", &c);




    printf("\n");








    SolveQuadratic(a, b, c);



    printf("\nThat's it!\n\n\n");


    return 0;
}
