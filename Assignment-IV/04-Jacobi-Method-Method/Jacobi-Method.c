
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// #define f1(x,y,z)  (11+2*y-z)/6
// #define f2(x,y,z)  (2*x - 2*z + 5)/7
// #define f3(x,y,z)  (x + 2*y + 1)/5

float func1(float x,float y, float z) {
	return (11 + 2 * y - z) / 6;
}
float func2(float x,float y, float z) {
	return (2*x - 2*z + 5)/7;
}
float func3(float x,float y, float z) {
	return (x + 2*y + 1)/5;
}

// #define f1(x,y,z)  (17-y+2*z)/20
// #define f2(x,y,z)  (-18-3*x+z)/20
// #define f3(x,y,z)  (25-2*x+3*y)/20

int main()
{

	float x0 = 0, y0 = 0, z0 = 0;
	float E1, E2, E3, E;
	float x0_new, y0_new, z0_new;

	printf("Enter tolerable error:");
 	scanf("%f", &E);
	int i = 0;

	do{

		x0_new = func1(x0, y0,z0);
		y0_new = func2(x0, y0,z0);
		z0_new = func3(x0, y0,z0);

		printf("Iteration %d :\n", i + 1);
		printf("\
		X = %.3f		\n\
		Y = %.3f		\n\
		Z = %.3f		\n",x0_new, y0_new, z0_new);

		  E1 = fabs(x0-x0_new);
		  E2 = fabs(y0-y0_new);
		  E3 = fabs(z0-z0_new);


		x0 = x0_new;
		y0 = y0_new;
		z0 = z0_new;

	} while (E1 > E && E2 > E && E3 > E);

	
	printf("\nSolution:\n\
	 x=%0.3f,\n\
	 y=%0.3f and \n\
	 z = %0.3f\n",x0_new, y0_new, z0_new);
}

	/*
		printf("\n _________________________________________________________________________________________________________\n");
		printf("    Iteration   |     x1      |       x2      |       x3      |       E1      |      E2    |	E3			  ");
		printf("\n _______________|_____________|_______________|_______________|_______________|____________|______________\n");

		// real calculation and the iteration begins here

		for (int i = 0; i <n; i++)
		{
			x_old0 = x0;
			x_old1 = x1;
			x_old2 = x2;

			x0 =calcX0(x0,x1,x2,a0,b0,c0,d0);
			x1 = calcX1(x0,x1,x2,a1,b1,c1,d1);
			x2 = calcX2(x0,x1,x2,a2,b2,c2,d2);

			x_new0 = x0;
			x_new1 = x1;
			x_new2 = x2;

			E0 = error(x_new0,x_old0);
			E1 = error(x_new1,x_old1);
			E2 = error(x_new2,x_old2);
			printf("    %d		|    %.3f    |     %.3f     |      %.3f    |      %.3f    |     %.3f  |	%.3f			  ",i+1,x0,x1,x2,E0,E1,E1);
			printf("\n _______________|_____________|_______________|_______________|_______________|____________|______________\n");


			if (E0 < 0.005 || E1 < 0.005 || E2 < 0.005)
			{
				break;
			}
		}
	*/
	// printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", Xn,e);

/*



6 -2 1 11
1 2 -5 -1
-2 7 2 5
5


from equations
		a0*x0 + b0*y0 + c0*z0 = d0
		a1*x0 + b1*y0 + c1*z0 = d1
		a2*x0 + b2*y0 + c2*z0 = d2
Enter the value of a0,b0,c0,d0: 6 -2 1 11
Enter the value of a1,b1,c1,d1: 1 2 -5 -1
Enter the value of a2,b2,c2,d2: -2 7 2 5
Enter the number of iteration: 4
Iteration 1 :

				X0 = 1.833
				X1 = -1.417
				X2 = 9.292
Iteration 2 :

				X0 = -0.188
				X1 = 22.823
				X2 = -77.568
Iteration 3 :

				X0 = 22.369
				X1 = -205.604
				X2 = 744.482
Iteration 4 :

				X0 = -190.782
				X1 = 1956.096
				X2 = -7034.617



				*/