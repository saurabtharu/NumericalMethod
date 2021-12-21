#include<stdio.h>

void input_value(float *x, float *f,int n) {

	float x_sum = 0, x2_sum = 0, x_mean;
	float y_sum = 0, xy_sum = 0, y_mean;

	printf("Enter the value of x and fx: \n");
	printf("x	fx\n");
	for (int i = 0; i < n; i++) {
		scanf("%f %f", (x + i),&f[i]);
	}

}


int main () { 
	int n;
	float x[10], f[10], val;
	float x_sum = 0, x2_sum = 0, x_mean;
	float y_sum = 0, xy_sum = 0, y_mean;
	float m, c;

	printf("Enter the number of data points: ");
	scanf("%d", &n);
	input_value( x, f,n);
	printf("Enter the value of x for which y is to be estimated : ");
	scanf("%f", &val);

	for (int i = 0; i < n; i++) {
		x_sum = x_sum + x[i];
		x2_sum = x2_sum + (x[i] * x[i]);
		y_sum = y_sum + f[i];
		xy_sum = xy_sum + (x[i]*f[i]);
	}
	x_mean = x_sum / n;
	y_mean = y_sum / n;
	m = (n*xy_sum-(x_sum*y_sum)) / (n*x2_sum - (x_sum*x_sum));
	c = y_mean - (m*x_mean);

	printf("The required eqn is y = %.3fx + %.3f\n\n",m,c);
	printf("The predicted value for y is: %.3f\n\n",m*val+c);
}


/*


Enter the number of data points: 5
Enter the value of x and fx: 
x   fx
1	3
2	5
3	7
4	10
5	12
Enter the value to be interpolted: 5
The required eqn is y = 2.300x + 0.500
*/

