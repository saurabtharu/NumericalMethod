#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void input_value(float *x, float *f,int n) {
	printf("Enter the value of x and fx: \n");
	printf("x   fx\n");
	for (int i = 0; i < n; i++) {
		scanf("%f %f", (x + i),&f[i]);
	}
}

void findU(float *u,float *x,int val,int n)
{
    for(int i = 0; i < n; i++)
    {
        u[i] = val - x[i];
        printf("\n U[%d] = %.3f\n",i, u[i]);
    }
}

void findH(float *h,float *x,int n)
{
	for(int i = 1; i < n; i++)
    {
        h[i] = x[i] - x[i-1];
        printf("\n H[%d] = %.3f\n",i, h[i]);
    }
}


void findA(float *a,float *f,float *h,int n)
{
    for(int i = 1; i < n-1; i++)
    {
        a[i] = ( 6*( (f[i+1]-f[i])/h[i+1] -  (f[i]-f[i-1])/h[i]  )  -  h[i]*a[i-1]  -  h[i+1]*a[i+1]  ) / (2*( h[i] + h[i+1] ));
        printf("\n A[%d] = %.3f\n",i, a[i]);
    }
}


void findS(float *s,float *a,float *h,float *u,float *x,float *f,int val,int n)
{
    int k;
    for(int i = 1; i < n; i++)
    {
        if(val>=x[i-1]&& val<=x[i]){
            s[i] =  a[i-1]/(6*h[i]) * ( pow(h[i],2)*u[i] - pow(u[i],2) )  +  a[i]/(6*h[i]) * ( pow(u[i-1],3)  - pow(h[i],2)*u[i-1]  )   +  1/h[i] * (f[i]*u[i-1]  - f[i-1]*u[i]);
            k = i;
        }
        printf("\n S[%d] = %.3f\n",i, s[i]);

    }
    printf("Value at %d using Cubic Splines Interpolation is %f\n",val, s[k]);

}


int main() {
	int n;
	float x[10], f[10], val;
	float *u, *h, *a;
	float *s;

	printf("Enter the number of data points: ");
	scanf("%d", &n);

    u = malloc(sizeof(float *));
    h = malloc(sizeof(float *));
    a = malloc(sizeof(float *));
    s = malloc(sizeof(float *));
    a[0]=0;
	a[n-1]=0;

    // fx = malloc(n * n * sizeof(float *));
	// x = malloc(n * sizeof(int*));
	input_value( x, f,n);

	printf("Enter the value to be interpolted: ");
	scanf("%f", &val);
	findU(u,x,val,n);
	findH(h,x,n);
	findA(a,f,h,n);
	findS(s,a,h,u,x,f,val,n);

}

/*
Enter the number of data points: 3
Enter the value of x and fx: 
x       fx
4   2
9   3
16  4
Enter the value to be interpolted: 7


Enter x:7
H[1] = 5
H[2] = 7
u[0] = 3
u[1] = -2
u[2] = -9
A[1] = -0.0142857
S[1] = 2.62286
s 2.62286% 
*/

