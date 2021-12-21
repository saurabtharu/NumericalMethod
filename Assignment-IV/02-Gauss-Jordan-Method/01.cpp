// This is the C++ source code for Gaussian Jordan or Gauss Jordan Method.
#include <iostream>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;


class GaussJordan
{
    public:
        GaussJordan();
        void setMatA();
        void setMatB();
        void solve();
        void setRowCol();
        bool pivotZero(int row);
        void normalize(int row);
        void exchangeRow(int row);
        void makeBelowPivotZero(int row);
        void makeAbovePivotZero(int row);
        void display();

    protected:

    private:
        double matrixA[5][5],x[5];
        int rowA,colA;
};
GaussJordan::GaussJordan()
{
    //ctor
}
void GaussJordan::setRowCol()
{
    cout << "Enter row of Matrix A: ";
    cin >> rowA;
    cout << "Enter column of Matrix A: ";
    cin >> colA;
}
void GaussJordan::setMatA()
{
    cout << "For Matrix A : " << endl;
    for(int i =  0; i < rowA; i++ )
    {
        for(int j = 0; j < colA; j++)
        {

            cout << "Enter matrixA[" << i << "]" << "[" << j << "] : " ;
            cin >> matrixA[i][j];
        }
    }
}
void GaussJordan::setMatB()
{
    cout << "For Matrix B: " << endl;
    for(int i =  0; i < rowA; i++ )
    {

            cout << "Enter B[" << i << "]" << "[" << 0 << "] : " ;
            cin >> matrixA[i][colA];
    }
}



void GaussJordan::display()
{
    for(int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA+1; j++)
        {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

 cout << endl << endl;
}



void GaussJordan::normalize(int row)
{
    //cout << "normalized \n";
    double normal = matrixA[row][row];
    for(int j = 0; j < colA+1; j++)
    {
        matrixA[row][j] /= normal;
    }
    display();
}


bool GaussJordan::pivotZero(int row)
{
    if(matrixA[row][row] == 0)
    {
        return true;
    }
    else
        return false;
}


void GaussJordan::exchangeRow(int row)
{
    //cout << "Exchanfged\n";
    int k = row+1;
    int great = row+1;
    while (k<rowA)
    {
        if(matrixA[great][row]<matrixA[k][row])
            great  = k;
        k++;
    }
    //cout << great << endl;

    for (int j = 0; j < colA+1; j++)
    {
        double temp;
        temp = matrixA[row][j];
        matrixA[row][j] = matrixA[great][j];
        matrixA[great][j] = temp;
    }
    display();
}

void GaussJordan::makeBelowPivotZero(int row)
{
    //cout << "made zero" << endl;
    for(int i = row+1; i < rowA; i++)
    {
        double zeroFactor = matrixA[i][row];
      //  cout << "zero = " << zeroFactor<< endl;
        for(int j = 0; j < colA+1; j++)
        {
            matrixA[i][j] -= zeroFactor*matrixA[row][j];
        }
        display();
    }

}
void GaussJordan::makeAbovePivotZero(int row)
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
        display();
    }

}

void GaussJordan::solve()
{
    for(int i = 0; i < rowA; i++)
    {
        if(!pivotZero(i))
        {
            normalize(i);
        }
        else
        {
            exchangeRow(i);
            normalize(i);
        }
        makeBelowPivotZero(i);
    }

    for(int i = rowA-1; i > 0; i--)
    {
        makeAbovePivotZero(i);
    }
}



int main()
{
    GaussJordan g1;
    cout << setprecision(4);
    g1.setRowCol();
    g1.setMatA();
    g1.setMatB();
    g1.solve();
    return 0;
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