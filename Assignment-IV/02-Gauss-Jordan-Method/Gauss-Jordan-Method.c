

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



void inputMatrixA(float mat[][10],int row,int col) {
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%f", &mat[i][j]);
		}
	}
}

void inputMatrixB(float mat[][10],int row,int col) {
	
	for (int i = 0; i < row; i++)
	{
		scanf("%f", &mat[i][col]);
	}
}


void display(float mat[][10],int row,int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < col+1; j++)
        {
			printf("\t%.3f   ", *(*(mat + i) + j));
		}
		printf("\n");
	}
	
    printf("\n\n");

}



void normalize(float matrixA[][10],int row,int rowA,int colA)
{
    //cout << "normalized \n";
    double normal = matrixA[row][row];
    for(int j = 0; j < colA+1; j++)
    {
        matrixA[row][j] /= normal;
    }
    display(matrixA,rowA,colA);
}



bool pivotZero(float matrixA[][10], int row)
{
    if(matrixA[row][row] == 0)
    {
        return true;
    }
    else
        return false;
}

void exchangeRow(float matrixA[][10],int row,int rowA,int colA)
{
  //  cout << "Exchanfged\n";
    int k = row+1;
    int great = row+1;
    while (k<rowA)
    {
        if(matrixA[great][row]<matrixA[k][row])
            great  = k;
        k++;
    }
    printf("\n%d\n",great );

    for (int j = 0; j < colA+1; j++)
    {
        double temp;
        temp = matrixA[row][j];
        matrixA[row][j] = matrixA[great][j];
        matrixA[great][j] = temp;
    }
    display(matrixA,rowA,colA);
}



void makeBelowPivotZero(float matrixA[][10],int row,int rowA,int colA)
{
   // cout << "made zero" << endl;
    for(int i = row+1; i < rowA; i++)
    {
        double zeroFactor = matrixA[i][row];
   //     cout << "zero = " << zeroFactor<< endl;
        for(int j = 0; j < colA+1; j++)
        {
            matrixA[i][j] -= zeroFactor*matrixA[row][j];
        }
        display(matrixA,rowA,colA);
    }

}

void makeAbovePivotZero(float matrixA[][10],int row,int rowA,int colA)
{
    //cout << "made zero" << endl;
    for(int i = row-1; i >= 0; i--)
    {
        double zeroFactor = matrixA[i][row];
       // cout << "zero = " << zeroFactor<< endl;
        for(int j = row; j < colA+1; j++)
        {
            matrixA[i][j] -= zeroFactor*matrixA[row][j];
        }
        display(matrixA,rowA,colA);
    }

}



void solve(float matrixA[][10],int row,int col)
{
    for(int i = 0; i < row; i++)
    {
        if(!pivotZero(matrixA,i)) 
       // this is done because if the pivot in any row is zero which creates error
        {
            normalize(matrixA,i,row,col);
        }
        else
        {
			exchangeRow(matrixA, i,row, col);
			normalize(matrixA, i,row, col);
		}
		makeBelowPivotZero(matrixA,i,row,col);
    }
    for(int i = row-1; i > 0; i--)
    {
        makeAbovePivotZero(matrixA,i,row,col);
    }
}



int main() {

	float matrixA[10][10], matrixB[10][10];
	int row, col;


	printf("Enter the number of rows: ");
	scanf("%d", &row);

	printf("Enter the number of columns: ");
	scanf("%d", &col);
	// matrixA = matrixB = malloc(row * col * sizeof(float *));

	printf("Enter the elements of matrix A:\n");
	inputMatrixA(matrixA, row, col);

	printf("Enter the elements of matrix B:\n");
	inputMatrixB(matrixA, row, col);

	// display(matrixA, row, col);
    // printf("\n-----------------------------\n");

 

    solve(matrixA, row, col);


	printf("\nThe Required values are:\n");
    for(int i = 0; i < row;i++)
    	printf("X[%d]: %.3f\n",i,matrixA[i][col]);

	printf("\n\n\n");
}







/*

➜  02-Gauss-Jordan-Method ./01
Enter the number of rows: 3 
Enter the number of columns: 3
Enter the elements of matrix A:
4 3 -1
1 1 1
3 5 3
Enter the elements of matrix B:
6
1
4
        1.000           0.750           -0.250          1.500   
        1.000           1.000           1.000           1.000   
        3.000           5.000           3.000           4.000   


        1.000           0.750           -0.250          1.500   
        0.000           0.250           1.250           -0.500   
        3.000           5.000           3.000           4.000   


        1.000           0.750           -0.250          1.500   
        0.000           0.250           1.250           -0.500   
        0.000           2.750           3.750           -0.500   


        1.000           0.750           -0.250          1.500   
        0.000           1.000           5.000           -2.000   
        0.000           2.750           3.750           -0.500   


        1.000           0.750           -0.250          1.500   
        0.000           1.000           5.000           -2.000   
        0.000           0.000           -10.000         5.000   


        1.000           0.750           -0.250          1.500   
        0.000           1.000           5.000           -2.000   
        -0.000          -0.000          1.000           -0.500   


        1.000           0.750           -0.250          1.500   
        0.000           1.000           0.000           0.500   
        -0.000          -0.000          1.000           -0.500   


        1.000           0.750           0.000           1.375   
        0.000           1.000           0.000           0.500   
        -0.000          -0.000          1.000           -0.500   


        1.000           0.000           0.000           1.000   
        0.000           1.000           0.000           0.500   
        -0.000          -0.000          1.000           -0.500   



The Required values are:
X[0]: 1.000
X[1]: 0.500
X[2]: -0.500


*/