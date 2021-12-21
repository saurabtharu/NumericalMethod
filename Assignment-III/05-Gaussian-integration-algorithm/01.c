// WAP to integrate using Gaussian integration algorithm,
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float func(float x){
	// return exp(pow(x,2)) -1;
	// return exp(x);
	return 1 / (1 + pow(x, 2));
	// return exp(-pow(x, 2));
	// return (log(x) + x * x * sin(x));
}




int main(){
	float result;
	int choice;

	printf("Choose the options below:\n\
	1. Two point		\n\
	2. Three points	\n\
	3. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	printf("\n\nThe upper limit and lower limit for finding integration using \nGaussian integration are 1 and -1 respectively\n\n");

		switch (choice)
		{
		case 1:
			result = func(-1 / sqrt(3)) + func(1 / sqrt(3));
			printf("The answer by gaussian 2 point is %.2f\n", result);
			break;
		case 2:
			result = 0.555 * func(-sqrt(0.6)) + 0.888 * func(0) + 0.555 * func(sqrt(0.6));
			printf("The answer by gaussian 3 point is %.2f\n", result);
			break;
		case 3:
			printf("Exiting program....\n");
			exit(0);

		default:
			printf("Opps!! Wrong choice...!!");
			break;
		}

	
}

