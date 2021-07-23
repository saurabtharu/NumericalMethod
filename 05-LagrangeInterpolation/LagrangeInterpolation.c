#include<stdio.h>
#define MAX 10

float lagrangeMethod(float *xArr,float *yArr, int n, float x){
	float sum = 0;
	float mult;

	for (int i = 0; i < n; i++)
	{ 
		mult=1.0;
		for(int j = 0; j< n; j++)
		{ 
			if(i!=j)
				mult = mult * (x - *(xArr+j)) / (*(xArr+i) - *(xArr+j));
		}
		sum = sum +mult * yArr[i];
	}
	return sum;
}

int main()
{
	int n;
	float x1, y1;

	float x[MAX], y[MAX], mult, sum;

	printf("Enter the number of degrees:   ");
	scanf("%d", &n);


	printf("Enter the values of x and y\n");
	printf("x | y\n");

	for (int i = 0; i < n; i++)
	{
		scanf("%f	%f", &x[i], &y[i]);
	}

	printf("Enter x where the interpolation is required: ");
	scanf("%f", &x1);

	y1 = lagrangeMethod(x, y, n, x1);

	printf("y= %.4f\n", y1);
}