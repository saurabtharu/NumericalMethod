// WAP to integrate using Romberg integration formulas,

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float func(float x){
	return 1/(1+x);
	// return log10(x);
	// return 1/(1 + pow(x,2));
	// return exp(-pow(x,2));
}
 
float trapezoidal(float a, float b,int n){
	float x=a;
	float result=0;
	float h = (b-a)/n;

	for (int i = 0; i <= n; i++)
	{
		if (i==0 || i==n)
		{
			result = result + func(x);
		} else {
			result = result + 2 * func(x);
		}
		x = x + h;
	}
	result = (h / 2) * result;
	return result;
}



void table(float h,float a,float b,int n)  {
	
	printf("\n\
	a = %.3f\n\
	b = %.3f\n\
	when n = %d\t h = %.3f\n",
		   a, b, n, h);

	printf("-----------------------------------\n");
	printf("    x		 	  fxi\n");
	printf("-----------------------------------\n");

	for (int i = 0; i < n + 1; i++)
	{

		printf("x%d = %.3f		y%d = %.3f\n",i,a + i*h,i,func(a + i*h));
	}
	printf("-----------------------------------\n");
	
}
void findH(float *h,float a,float b,int n)  {
	*h = (b - a) / n;
	
}

int main(){
	float a,b,h,i=0.0;
	float result=0;
	float i1, i2, i3, i4, i5, I;

	printf("Enter the value of lower limit: ");
	scanf("%f",&a);
	printf("Enter the value of upper limit: ");
	scanf("%f",&b);

	// for n = 2
	findH(&h, a, b, 2);
	table(h, a, b, 2);
	i1 = trapezoidal(a, b, 2);
	printf("i1 = %.3f\n", i1);
	printf("***********************************\n\n");


	// for n = 4
	findH(&h, a, b, 4);
	table(h, a, b, 4);
	i2 = trapezoidal(a, b, 4);
	printf("i2 = %.3f\n", i2);
	printf("***********************************\n\n");

	// for n = 8
	findH(&h, a, b, 8);
	table(h, a, b, 8);
	i3 = trapezoidal(a, b, 8);
	printf("i3 = %.3f\n", i3);
	printf("***********************************\n\n");

	i4 = (4*i2 - i1)/3;
	printf("i4 = %.3f\n", i4);
	printf("***********************************\n\n");


	i5 = (4*i3 - i2)/3;
	printf("i5 = %.3f\n", i5);
	printf("***********************************\n\n");
	
	I = (4*i5-i4)/3;
	printf("I = %.3f\n", I);
	printf("***********************************\n\n");

	printf("Hence,the final answer using Romberg Integration is: %.3f\n",I);
}


/*


➜  06-Romberg-integration-formulas ./01
Enter the value of lower limit: 0
Enter the value of upper limit: 1

        a = 0.000
        b = 1.000
        when n = 2       h = 0.500
-----------------------------------
    x                     fxi
-----------------------------------
x0 = 0.000              y0 = 1.000
x1 = 0.500              y1 = 0.667
x2 = 1.000              y2 = 0.500
-----------------------------------
i1 = 0.708
***********************************


        a = 0.000
        b = 1.000
        when n = 4       h = 0.250
-----------------------------------
    x                     fxi
-----------------------------------
x0 = 0.000              y0 = 1.000
x1 = 0.250              y1 = 0.800
x2 = 0.500              y2 = 0.667
x3 = 0.750              y3 = 0.571
x4 = 1.000              y4 = 0.500
-----------------------------------
i2 = 0.697
***********************************


        a = 0.000
        b = 1.000
        when n = 8       h = 0.125
-----------------------------------
    x                     fxi
-----------------------------------
x0 = 0.000              y0 = 1.000
x1 = 0.125              y1 = 0.889
x2 = 0.250              y2 = 0.800
x3 = 0.375              y3 = 0.727
x4 = 0.500              y4 = 0.667
x5 = 0.625              y5 = 0.615
x6 = 0.750              y6 = 0.571
x7 = 0.875              y7 = 0.533
x8 = 1.000              y8 = 0.500
-----------------------------------
i3 = 0.694
***********************************

i4 = 0.693
***********************************

i5 = 0.693
***********************************

I = 0.693
***********************************

Hence,the final answer is: 0.693


*/