//forward divided difference  table
// WAP to calculate derivatives from divided difference table

#include<stdio.h>
#include<stdlib.h>


void input_value(float x[10], float fx[][10],int n) {
	printf("Enter the value of x and fx: \n");
	printf("x 	fx\n");
	for (int i = 0; i < n; i++) {
		scanf("%f %f", (x + i),&fx[0][i]);
	}
}

void dividedDiffTable(float x[10], float fx[][10], int n) {
	for(int i = 1; i < n; i++) {
        for(int j = 0; j< n-i;j++) {
            // fx[i][j] = (fx[i-1][j+1]-fx[i-1][j])/(x[i+j]-x[j]) ;					// for unequal interval between values of x
            fx[i][j] = (fx[i-1][j+1]-fx[i-1][j]) ;									// for unequal interval between values of x
            if(fx[i][j] < 0.0000009 && fx[i][j] > 0 || fx[i][j] >-0.0000009 && fx[i][j]<0)
                    fx[i][j] = 0;
        }
    }

    printf("\n");
    printf("Sn  Xi\t\tf(Xi)\t\t");


    for(int i = 0; i <n-1;i++) {
        printf("%d diff\t\t", i+1 );
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
		 printf("%d   %.3f \t", i + 1, x[i]);
		 for (int j = 0; j < n - i; j++) {
			 printf("%.3f\t\t",fx[j][i] ) ;
        }
        printf("\n");
    }
}



void findH(float *h, float *x) {
    *h = x[1] - x[0];
}

void findS(float *s, float *x,float val,float h,int n){
    *s = (val - x[0])/h;
}

void delValues(float del[],float fx[][10],int n) {
    for(int i = 1;i<n;i++) {
        if(i<n)
         del[i]=fx[i][0];
        else
            del[i] = 0;
    }

    // for(int i = 1;i<n;i++)
    // {
	// 	printf("    %d", del[i]);
	// }
}

// for forward divided differenc 
void firstDerivative(float h,float s,float *f1,float *del) {        // for first order derivative
    *f1 = 1 / h * ( del[1] + 1/2.0 * (2 * s -1 ) * del[2] + 1 / (6.0) * (3*s*s - 6 *s +2)*
         del[3] + 1 /(24.0) *( 4*s*s*s-18*s*s+22*s-6)*del[4]);
}

void secondDerivative(float h,float s,float *f2,float *del) {       // for second order derivative
    *f2 = 1 / (h*h) * (del[2] + 1/6.0 * (6*s-6) * del[3] + 1/24.0 *(12*s*s-36*s+22)*del[4]);
}



int main() {

	int n;
	float x[10], fx[10][10], val;
    float h, s,*del;
    float f1, f2;

    printf("Enter the number of data points: ");
	scanf("%d", &n);

    del = malloc(n * sizeof(float *));

    // fx = malloc(n * n * sizeof(int *));
	// x = malloc(n * sizeof(int*));
	input_value( x, fx,n);

    printf("Enter the value at which first and second derivative is to be calculated: ");
	scanf("%f", &val);

    dividedDiffTable(x, fx, n);
    findH(&h, x);
    findS(&s, x, val, h, n);
    delValues(del, fx, n);
    firstDerivative(h, s, &f1, del);
    secondDerivative(h, s, &f2, del);

    printf("\n------------------------------------------------------------------------------------\n");

    printf("\nh = %.3f\n",h);
    printf("s = %.3f\n",s);


    printf("\nThe value of f1 : %.3f\n", f1);
    printf("The value of f2 : %.3f\n", f2);
}


/*


1.5	3.375
2.0	7.0
2.5	13.625
3.0	24
3.5	38.875
4.0	59


*/
