
#include<stdio.h>
#include<math.h>
#include<stdlib.h>



float func1(float w,float x,float y,float z,float a) {
	return (x + y - a) / 4;
}
float func2(float w,float x,float y,float z,float a) {
	return (w + z - a) / 4;
}
float func3(float w,float x,float y,float z,float a) {
	return (w + z - a) / 4;
}
float func4(float w,float x,float y,float z,float a) {
	return (x + y - a) / 4;
}


void Gauss_Seidal_method(float E,float *b){
	
	float w0 = 0,x0 = 0, y0 = 0, z0 = 0;
	float E1, E2, E3,E4;
	float a;
	float w0_new,x0_new, y0_new, z0_new;


	int i = 0;
	printf("Iteration	 u1		u2		u3		u4		\n");
	do{

		w0_new = func1(w0, x0,y0, z0,b[0]);
		x0_new = func1(w0_new, x0,y0,z0,b[1]);
		y0_new = func2(w0_new, x0_new,y0,z0,b[2]);
		z0_new = func3(w0_new,x0_new, y0_new,z0,b[3]);

		printf("  %d		%.3f		%.3f		%.3f		%.3f	\n",i+1,w0_new,x0_new, y0_new, z0_new);
		E1 = fabs(w0-w0_new);
		E2 = fabs(x0-x0_new);
		E3 = fabs(y0-y0_new);
		E4 = fabs(z0-z0_new);


		w0 = w0_new;
		x0 = x0_new;
		y0 = y0_new;
		z0 = z0_new;
		i++;
	} while (E1 > E && E2 > E && E3 > E && E4 > E);

		printf("\nSolution:\n\
	 u1 = %0.3f,\n\
	 u2 = %0.3f,\n\
	 u3 = %0.3f and \n\
	 u4 = %0.3f\n",w0_new,x0_new, y0_new, z0_new);
}

int main () {
	int n,k;			//  dimension of plate
	float tl, tr, tu, tb;		//temperature in left, right, upper and bottom part of the plate
	float a[10][10],b[10];
	float error;
	float new_x[10],old_x[10];
	float E[10];
	int i,j;

	printf("Enter the dimension of plate: ");
	scanf("%d", &n);

	printf("Enter the temperature in left, right, bottom and upper part of the plate: ");
	scanf("%f %f %f %f", &tl, &tr, &tb, &tu);

	// construction of RHS vector

	for (i = 0; i <= n;i++)
		b[i] = 0;
	k = 0;

	b[0] = -(tl + tb);
	b[1] = -(tb + tr);
	b[2] = -(tl + tu);
	b[3] = -(tu + tr);

	printf("Enter the accuracy limit: ");
	scanf("%f", &error);
	
	printf("\nRSH vector is\n");
	for (i = 0; i < n; i++)
	{
		printf("	%.3f\n", b[i]);
	}

	printf("\nGauss Seidal method:\n");
	Gauss_Seidal_method(error, b);

}
