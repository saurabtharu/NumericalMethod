#include <iostream>
using namespace std;

class DerivativeBackward
{
public:
    void askN();
    void askX();
    void askF();
    void askXX();
    void forwardTable();
    void calcd1();
    void calcd2();
    void findH();
    void solve();
    void fillDelF();
    void findS();
private:
    double XX, x[10] , f[10][10] , p[10],diff[10][10],P1,delF[10],f1,f2;
    int n;
    double h,s;

};

void DerivativeBackward::askX()
{
    cout << endl;
    for(int i = 0; i<n; i++ )
    {
        cout << "ENter X[" << i  << "] : ";
        cin >> x[i];
    }
    cout << endl;
}

void DerivativeBackward::askF()
{

    for(int j = 0; j<n; j++ )
    {
        cout << "ENter F[" << j  << "] : ";
        cin >> f[0][j];
    }
    cout << endl;
}
void DerivativeBackward::askXX()
{

    cout << "Enter X for which the value is to be found: ";
    cin >> XX;
}

void DerivativeBackward::forwardTable()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j< n-i;j++)
        {
            f[i][j] = (f[i-1][j+1]-f[i-1][j]);
            if(f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] >-0.0000009 && f[i][j]<0)
            {
                    f[i][j] = 0;
            }
        }
    }
    cout << endl;
    cout << "Sn\tXi\tf(Xi)\t";
    for(int i = 0; i <n-1;i++)
    {
        cout << i+1 << " diff\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
         cout <<i+1 <<"\t" << x[i]<< "\t";
        for(int j = 0; j< n-i;j++)
        {
            cout  << f[j][i] << "\t";
        }
        cout << endl;
    }
}

void DerivativeBackward::findH()
{
    h = x[1] - x[0];
    cout << "h = " <<h;
}
void DerivativeBackward::findS()
{
    s = (XX - x[n-1])/h;
    cout << "s = " <<s;
}
void DerivativeBackward::solve()
{
    findH();
    findS();
    fillDelF();
    calcd1();
    calcd2();


    cout <<endl << "The value of f1 :" << f1;
    cout <<endl << "The value of f2 :" << f2;
    cout  << endl << endl;
}


void DerivativeBackward::fillDelF()
{
    for(int i = 1;i<n;i++)
    {
        if(i<n)
         delF[i] = f[i][n-i-1];
        else
            delF[i] = 0;
    }
    for(int i = 1;i<n;i++)
    {
		cout << endl;
        cout<< delF[i];
	}
}

void DerivativeBackward::calcd1()
{
    f1 = 1 / h * ( delF[1] + 1/2.0 * (2 * s +1 ) * delF[2] + 1 / (6.0) * (3*s*s + 6 *s +2)*delF[3]
        + 1 /(24.0) *( 4*s*s*s+18*s*s+22*s+6)*delF[4]);
}

void DerivativeBackward::calcd2()
{
    f2 = 1 / (h*h) * (delF[2] + 1/6.0 * (6*s+6) * delF[3] + 1/24.0 *(12*s*s+36*s+22)*delF[4]);

}
void DerivativeBackward::askN()
{
    cout << "Enter the number of values: ";
    cin >> n;
}
int main()
{

    DerivativeBackward d1;
    d1.askN();
    d1.askX();
    d1.askF();
    d1.askXX();
    d1.forwardTable();
    d1.solve();
}




/*

➜  01-derivatives-from-divided-difference-table ./02         
Enter the number of values: 6

X  			Y
 1.5    	3.375
 2.0    	7
 2.5    	13.625
 3.0    	24
 3.5    	38.875
 4.0    	59
*/

/*



  01-derivatives-from-divided-difference-table ./02         
Enter the number of values: 6

1.5
2 
2.5
3
3.5
4

3.375
7
13.625
24
38.875
59 

Enter X for which the value is to be found: 1.5

Sn      Xi      f(Xi)   1 diff  2 diff  3 diff  4 diff  5 diff
1       1.5     3.375   3.625   3       0.75    0       0
2       2       7       6.625   3.75    0.75    0
3       2.5     13.625  10.375  4.5     0.75
4       3       24      14.875  5.25
5       3.5     38.875  20.125
6       4       59
h = 0.5s = -520.1255.250.75000000
The value of f1 :4.75
The value of f2 :9


*/





/*



*/