// WAP to integrate using Rung Kutta method

#include<stdio.h>

float func(float x,float y){
	// return 2*x*x*x -3*x*y;
	return 1 - 2*x*x*y;
	// return x*y;
	// return x*x + y*y;
	// return x + y;
	// return 1/(1+x);
	// return log10(x);
	// return 1/(1 + pow(x,2));
	// return exp(-pow(x,2));
}


float rungeKuttaMethod(float h,float x,float y,float val)  {
	float m1, m2, m3, m4, result;

	while (x <= val) {

		// printf("y(%.3f) = %.3f\n",x,y);
		printf("when x = %.3f then y = %.3f\n",x,y);
		if (x == val)
			return y;
		m1 = func(x, y);
		m2 = func(x + (h/2), y + (m1 * h)/2);
		m3 = func(x + (h/2), y + (m2 * h) / 2);
		m4 = func(x + h, y + m3 * h);
		// printf("m1 = %f m2 = %f m3 = %f m4 = %f\n", m1, m2,m3,m4);
		x = x + h;
		y = y + (h / 6) * (m1 + 2*m2 + 2*m3 + m4);
	} 
}

int main() {
	float a, b;
	float h;
	float val,result;

	// printf("When x = 1 then y =  1\n");

	printf("Enter the initial value of x and y: ");
	scanf("%f %f", &a,&b);

	printf("Enter the value of x for which y is to be calculated: ");
	scanf("%f", &val);
	
	printf("Enter the value of h : ");
	scanf("%f", &h);

	printf("\n");
	result = rungeKuttaMethod(h,a,b, val);
	printf("\nHence, the final answer is y(%.3f) = %.3f\n", val, result);

}


/*


Enter the initial value of x and y: 1 0
Enter the value of x for which y is to be calculated: 1.5
Enter the value of h : .25

when x = 1.000 then y = 0.000
when x = 1.250 then y = 0.180
when x = 1.500 then y = 0.225

Hence, the final answer is y(1.500) = 0.225
*/
