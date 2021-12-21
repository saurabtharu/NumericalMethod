// WAP to Integrate using Simpson’s 3/8 rule`

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float func(float x){
	// return exp(pow(x,2)) -1;
	return 1/(1 + pow(x,2));
	// return (x * x * x + 1);
}

float calc(float a, float b,int n){
	float x=a;
	float result=0;
	float h = (b-a)/n;

	for (int i = 0; i <= n; i++)
	{
		if (i==0 || i==n)
		{
			result = result + func(x);
		}else if(i%3==0){
			result = result + 2* func(x);
		} else {
			result = result + 3 * func(x);
		}
		x = x + h;
	}
	result = (3*h / 8) * result;
	return result;
}


void table(float h,float a,float b,int n)  {
	
	printf("\n\
	a = %.3f\n\
	b = %.3f\n\
	n = %d\n\
	h = %.3f\n",
		   a, b, n, h);

	printf("-----------------------------------\n");
	printf("    x		 	  fxi\n");
	printf("-----------------------------------\n");

	for (int i = 0; i < n + 1; i++)
	{

		printf("x%d = %.3f		y%d = %.3f\n",i,a + i*h,i,func(a + i*h));
	}
	printf("-----------------------------------\n\n");
	
}
void findH(float *h,float a,float b,int n)  {
	*h = (b - a) / n;
	
}

int main(){
	float a,b,h,i=0.0;
	int n;
	float result;
	float *fxi,*xi;

	printf("Enter the number of segments: ");
	scanf("%d",&n);

	printf("Enter the value of lower limit: ");
	scanf("%f",&a);
	printf("Enter the value of upper limit: ");
	scanf("%f",&b);

	h = (b - a) / n;
	findH(&h, a, b, n);

	table(h, a, b, n);

	result = calc(a, b, n);
	printf("Hence,the final answer is: %.4f\n",result);
}