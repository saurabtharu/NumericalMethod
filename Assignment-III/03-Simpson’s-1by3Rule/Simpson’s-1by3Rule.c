// WAP to Integrate using Simpson’s 1/3 rule 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float func(float x){
	// return exp(pow(x,2)) -1;
	return 1/(1 + pow(x,2));

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
		}else if(i%2!=0){
			result = result + 4* func(x);
		} else {
			result = result + 2 * func(x);
		}
		x = x + h;
	}
	result = (h / 3.0) * result;
	return result;
}

/*
void table(float h,float a,float b,int n, float fxi[],float xi[])  {

	printf("-----------------------------------\n");
	printf("    x		   fxi\n");
	printf("-----------------------------------\n");
	
	for (int i = 0; i <=n; i++)
	{
		printf("%.3f     %.3f\n", a + i*h, func(a + i*h));
	}
	printf("-----------------------------------\n\n");

}
*/

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

	findH(&h, a, b, n);

	table(h, a, b, n);

	result = calc(a, b, n);
	printf("Hence,the final answer is: %.4f\n",result);
}

/*


float func(float x){
	// return exp(pow(x,2)) -1;
	return 1.0/(1 + x*x);

}

void findH(float *h,float a,float b,int n) {
	*h = (b-a) / n;
}

void table(float h,float a,float b,int n, float fxi[],float xi[],float result[])  {
	*result = 0;

	printf("-----------------------------------\n");
	printf("    x		   fxi\n");
	printf("-----------------------------------\n");
	// xi[0] = a;
	// fxi[0] = func(0);
	// printf("x%d = %.3f	f(x%d) = %.3f\n", 0, xi[0], 0, fxi[0]);
	
	// xi[0] = a;
	// printf("\nx0=%f y0=%f\n", xi[0], func(xi[0]));

	for (int i = 0; i < n + 1; i++)
	{
		// fxi[i] = func(xi[i]);
		xi[i] = a + i*h;
		fxi[i] = func(a + i*h);
		printf("%.3f		 %.3f\n",xi[i],fxi[i] );
		// printf("%.3f		 %.3f\n", xi[i], fxi[i]);
	}
	printf("-----------------------------------\n\n");
	
	// for (int i = 0; i <=n; i++)
	// {
	// 	printf("%.3f     %.3f\n", a + i*h, func(a + i*h));
	// }
	// printf("-----------------------------------\n\n");

}

float calc(float fxi[],float h,int n){

	float result=0;
	for (int i = 0; i < n; i++)
	{
		if (i==0 || i ==n)
		{
			result += fxi[i];
		}else if (i%2!=0)
		{
			result += 4 * fxi[i];
		} else {
			result += 4 * fxi[i];
		}
	}
	result = (h / 3) * result;
	return result;
}

int main(){
	float a,b, h;
	int n;
	float result;
	float *fxi,*xi;

	printf("Enter the number of segments: ");
	scanf("%d",&n);

	fxi = xi = malloc((n + 1) * sizeof(float *));

	printf("Enter the value of lower limit: ");
	scanf("%f",&a);
	printf("Enter the value of upper limit: ");
	scanf("%f",&b);

	findH(&h, a, b,n);
	printf("\
	a = %.3f\n\
	b = %.3f\n\
	n = %d\n\
	h = %.3f\n",a, b, n, h);
	table(h, a, b, n, fxi, xi, &result);

	result = calc(fxi,h,n);
	printf("By Simpson's 1/3 rule, we get the value : %.4f\n", result);
	// printf("Hence,the final answer is: );
}


*/