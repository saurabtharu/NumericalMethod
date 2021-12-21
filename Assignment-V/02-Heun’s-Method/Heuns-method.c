// WAP to integrate using Heun;s Method

#include<stdio.h>

float func(float x,float y){
	// return 2*x*x*x -3*x*y;
	// return x*y;
	return x*x + y*y;
	// return 1/(1+x);
	// return log10(x);
	// return 1/(1 + pow(x,2));
	// return exp(-pow(x,2));
}


float heunsMethod(float h,float x,float y,float val)  {
	float m1, m2, result;

	printf("\n");
	while (x <= val)
	{

		printf("y(%.3f) = %.3f\n",x,y);
		if (x == val)
			return y;
		// printf("when x = %.3f then y = %.3f\n",x,y);
		m1 = func(x, y);
		m2 = func(x + h, y + m1 * h);
		x = x + h;
		// printf("x = %f m1 = %f m2 = %f\n", x, m1, m2);
		y = y + (h / 2) * (m1 + m2);
	}
}


int main() {
	float a, b;
	float h;
	float val,result;


	printf("Enter the initial value of x and y: ");
	scanf("%f %f", &a,&b);

	printf("Enter the value of x for which y is to be calculated: ");
	scanf("%f", &val);
	
	printf("Enter the value of h : ");
	scanf("%f", &h);

	result = heunsMethod(h,a,b, val);
	printf("\nHence, the final answer is y(%.3f) = %.3f\n", val, result);


}

/*


Enter the initial value of x and y: 0 0
Enter the value of x for which y is to be calculated: .4
Enter the value of h : .2

y(0.000) = 0.000
y(0.200) = 0.004
y(0.400) = 0.024

Hence, the final answer is y(0.400) = 0.024

*/
