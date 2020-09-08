#include <stdio.h>
#include <stdlib.h>
#include <math.h>





void SolveLinear(double a, double b)
{

    if (a == 0 && b != 0)

     printf("\tNo roots!\n");


    if (a == 0 && b == 0)

     printf("\tAny number is a root!\n");


    if (a != 0)

     {

       if ((-b / a) == -0)// prints 0 istead of -0

       printf("\tThere is only one root: x = 0\n");

       else

        printf("\tThere is only one root: x = %lg\n", -b / a);

     }

}







void SolveQuadratic(double a, double b, double c)
{
   if (a != 0)
   {

            if ((b*b - 4*a*c) < 0)

                  printf("\tNo roots!\n");



            if ((b*b - 4*a*c) > 0)

              {


                  printf("\tThere are two roots: x = %lg\n\n", (-b - sqrt(b*b - 4*a*c))/(2*a));

                  printf("\t                     x = %lg\n", (-b + sqrt(b*b - 4*a*c))/(2*a));


              }



            if ((b*b - 4*a*c) == 0)

              {


                if ((-b / a) == -0)// prints 0 istead of -0

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


    double a = 0, b = 0, c = 0, var = 0; // coeffs and var to check input

    int i = 0; //iteration counter for do...while loop


    printf("\n\tQuadraticSolver by AG, v. 1.1\n");

    printf("\n\tPlease, enter coeffs of a quadratic equation ax^2 + bx + c = 0\n\n");





    do
        {

            i++;




            if (i != 1) //if this is not the first iteration, prints error message

            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");





            printf ("                   a = ");

            var = scanf("%lg", &a);

            fflush(stdin);

            printf("\n");


        }  while (var != 1);


    i = 0;







    do
        {

            i++;




            if (i != 1) //if this is not the first iteration, prints error message

            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");





            printf ("                   b = ");

            var = scanf("%lg", &b);

            fflush(stdin);

            printf("\n");


        }  while (var != 1);


    i = 0;







    do
        {

            i++;




            if (i != 1) //if this is not the first iteration, prints error message

            printf ("\tSeems like something is wrong with the input. Try again, please\n\n");




            printf ("                   c = ");

            var = scanf("%lg", &c);

            fflush(stdin);

            printf("\n");


        }  while (var != 1);


    i = 0;






    SolveQuadratic(a, b, c);



    printf("\n\tThat's it!\n\n\n");


    return 0;
}
