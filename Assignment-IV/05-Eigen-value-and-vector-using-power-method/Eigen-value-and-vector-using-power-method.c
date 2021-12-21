
#include<stdio.h>
#include<math.h>
#define SIZE 10

int main () {
	float mat[SIZE][SIZE], x[SIZE],x_new[SIZE];
	float temp, lambda_new, lambda_old, error;
	int i,j,n, step=1;

	printf("Enter Order of Matrix: ");
	scanf("%d", &n);

	printf("Enter Coefficient row wise:\n");
	for (int i=1; i <= n; i++) {
		for (int j =1; j <= n; j++) {
			scanf("%f", &mat[i][j]);
		}
	}
	printf("Enter Initial Guess Vector:\n");
	for(i=1;i<=n;i++) {
		 scanf("%f", &x[i]);
	}
	printf("Enter Accuracy Limlit: ");
	scanf("%f", &error);

	/* Initializing Lambda_Old */
	lambda_old = 1;
	/* Multiplication */
	up:
	for(i=1;i<=n;i++) {
		 temp = 0.0;
		 for(j=1;j<=n;j++) {
		  	temp = temp + mat[i][j]*x[j];
		 }
		 x_new[i] = temp;
	}
	/* Replacing */
	for(i=1;i<=n;i++) {
	 	x[i] = x_new[i];
	}
	/* Finding Largest */
	lambda_new = fabs(x[1]);
	for(i=2;i<=n;i++) {
		 if(fabs(x[i])>lambda_new) {
		  	lambda_new = fabs(x[i]);
		 }
	}
	/* Normalization */
	for(i=1;i<=n;i++) {
	 	x[i] = x[i]/lambda_new;
	}
	/* Display */
	printf("\n\nIteration-%d:\n", step);
	printf("Eigen Value = %.3f\n", lambda_new);
	printf("Eigen Vector:\n");
	for(i=1;i<=n;i++) {
	 	printf("%.3f\t", x[i]);
	}
	printf("\n");
	/* Checking Accuracy */
	if(fabs(lambda_new-lambda_old)>error) {
		 lambda_old=lambda_new;
		 step++;
		 goto up;
	}
}




/*


5 4 2
4 5 2
2 2 2


0  1 0





2 4 
6 7


4 7 

0.001

*/