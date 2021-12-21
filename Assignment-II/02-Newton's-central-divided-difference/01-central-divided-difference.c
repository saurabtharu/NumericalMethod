//WAP to implement Newton's Central Divided Difference

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
            fx[i][j] = (fx[i-1][j+1]-fx[i-1][j])/(x[i+j]-x[j]) ;					// for unequal interval between values of x
            // fx[i][j] = (fx[i-1][j+1]-fx[i-1][j]) ;									// for unequal interval between values of x
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

void calculation(float x[10], float fx[][10], int n,int xx){
	int P1 = 0;
	for (int i = 0; i < n; i++)
	{
        double k = 1;
        for(int j = 0; j<i;j++) {
            k*=  (xx - x[j]);
        }
        P1 += k * fx[i][0];

    }
    printf("\n\nThe value of P%d(%d): %d \n\n" ,n-1,xx, P1);

}




int main() {
	int n;
	float x[10], fx[10][10], val;

	printf("Enter the number of data points: ");
	scanf("%d", &n);
	
	
	// fx = malloc(n * n * sizeof(int *));
	// x = malloc(n * sizeof(int*));
	input_value( x, fx,n);

	printf("Enter the value to be interpolted: ");
	scanf("%f", &val);
	dividedDiffTable(x, fx, n);
	calculation(x, fx, n, val);
}


/* 


Enter the number of data points: 5
Enter the value of x and fx: 
x       fx
10	0.1736
20	0.3420
30	0.5
40	0.6428
50	0.7660

*/


/*

Enter the number of data points: 4
Enter the value of x and fx: 
x       fx
0	648
2	704
3	729
6	792
Enter the value to be interpolted: 4


*/

/*

Enter the number of data points: 5    
Enter the value of x and fx: 
x       fx
1.1   0.6981
2	  1.4715
3.5   2.1287
5     2.0521
7.1   1.4480
Enter the value to be interpolted: 5

*/
