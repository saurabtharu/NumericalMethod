// WAP to integrate using Euler Method

#include<stdio.h>

float func(float x,float y){
	// return 2*x*x*x -3*x*y;
	return x*y;
	// return 1/(1+x);
	// return log10(x);
	// return 1/(1 + pow(x,2));
	// return exp(-pow(x,2));
}


float eulerMethod(float h,float x,float y,float val)  {

	printf("\n");
	while (x <= val)
	{

		printf("y(%.3f) = %.3f\n",x,y);
		if (x == val)
			return y;
		// printf("when x = %.3f then y = %.3f\n",x,y);
		y = y + h * func(x, y);
		x = x + h;
	}
}


int main() {
	float a, b;
	float h;
	float val;
	float result;

	// printf("When x = 1 then y =  1\n");

	printf("Enter the initial value of x and y: ");
	scanf("%f %f", &a,&b);

	printf("Enter the value of x for which y is to be calculated: ");
	scanf("%f", &val);
	
	printf("Enter the value of h : ");
	scanf("%f", &h);

	result  = eulerMethod(h,a,b, val);
	printf("\nHence, the final answer is y(%.3f) = %.3f\n", val, result);


}


/*

Enter the initial value of x and y: 1 1
Enter the value of x for which y is to be calculated: 2 
Enter the value of h : .25

y(1.000) = 1.000
y(1.250) = 1.250
y(1.500) = 1.641
y(1.750) = 2.256
y(2.000) = 3.243

Hence, the final answer is y(2.000) = 3.243
*/

