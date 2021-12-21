#include <iostream>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;


class GaussElimination
{
    public:

        void setMatA();
        void setMatB();
        void solve();
        void setRowCol();
        bool pivotZero(int row);
        void normalize(int row);
        void exchangeRow(int row);
        void makeBelowPivotZero(int row);
        void substitute();

        void display();

    protected:

    private:
        double a[5][5],x[5];
        int rowA,colA;
};

void GaussElimination::setRowCol()
{
    cout << "Enter row of Matrix A: ";
    cin >> rowA;
    cout << "Enter column of Matrix A: ";
    cin >> colA;
}
void GaussElimination::setMatA()
{
    cout << "For Matrix A : " << endl;
    for(int i =  0; i < rowA; i++ )
    {
        for(int j = 0; j < colA; j++)
        {

            cout << "Enter A[" << i << "]" << "[" << j << "] : " ;
            cin >> a[i][j];
        }
    }
}   
void GaussElimination::setMatB()
{
    cout << "For Matrix B: " << endl;
    for(int i =  0; i < rowA; i++ )
    {

            cout << "Enter B[" << i << "]" << "[" << 0 << "] : " ;
            cin >> a[i][colA];
    }
}

void GaussElimination::display()
{
    cout << setprecision(4) << endl;
    for(int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA+1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

 cout << endl << endl;
}


void GaussElimination::normalize(int row)
{
    //cout << "normalized \n";
    double normal = a[row][row];
    for(int j = 0; j < colA+1; j++)
    {
        a[row][j] /= normal;
    }
    display();
}


void GaussElimination::substitute()
{
    x[rowA-1] = a[rowA-1][colA];


    for(int i = rowA-2; i>=0 ;i--)
    {
        double s = 0;
        for(int j = i+1; j < colA; j++)
        {
            s+= a[i][j] * x[j];
        }
        x[i] = a[i][colA] - s;
    }
    cout << endl << "The Required values are:\n";
    for(int i = 0; i < rowA;i++)
    cout << "X["<<i<<"]: "<< x[i] << endl;

}
bool GaussElimination::pivotZero(int row)
{
    if(a[row][row] == 0)
    {
        return true;
    }
    else
        return false;
}

void GaussElimination::exchangeRow(int row)
{
  //  cout << "Exchanfged\n";
    int k = row+1;
    int great = row+1;
    while (k<rowA)
    {
        if(a[great][row]<a[k][row])
            great  = k;
        k++;
    }
    cout << great << endl;

    for (int j = 0; j < colA+1; j++)
    {
        double temp;
        temp = a[row][j];
        a[row][j] = a[great][j];
        a[great][j] = temp;
    }
    display();
}




void GaussElimination::makeBelowPivotZero(int row)
{
   // cout << "made zero" << endl;
    for(int i = row+1; i < rowA; i++)
    {
        double zeroFactor = a[i][row];
   //     cout << "zero = " << zeroFactor<< endl;
        for(int j = 0; j < colA+1; j++)
        {
            a[i][j] -= zeroFactor*a[row][j];
        }
        display();
    }

}



void GaussElimination::solve()
{
    for(int i = 0; i < rowA; i++)
    {
        if(!pivotZero(i)) 
       // this is done because if the pivot in any row is zero which creates error
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
    substitute();
}

int main()
{
    GaussElimination g1;


    g1.setRowCol();
    g1.setMatA();
    g1.setMatB();
    g1.solve();
    return 0;
}


/*

1
10 
1
10
1
1
1
1
10


*/