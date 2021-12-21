
#include <iostream>

using namespace std;


class GaussSiedel
{

public:
    GaussSiedel()
    {
        x0=x1=x2 = 0;
    }
    void askEqn();
    void no_Iterate();
    void solve();
    void calcX0();
    void calcX1();
    void calcX2();

private:
    double a0,b0,c0,a1,b1,c1,a2,b2,c2,d0,d1,d2;
    double x0,x1,x2;
    double num;

};

void GaussSiedel::askEqn()
{
    cout << "For the eqn a0x0 + b0x1 + c0x2 = d0 , Enter a0,b0,c0,d0:\n";
    cin >>a0 >>b0>>c0>>d0;
    cout << "For the eqn a1x0 + b1x1 + c1x2 = d1 , Enter a1,b1,c1,d1:\n";
    cin >>a1 >>b1>>c1>>d1;
    cout << "For the eqn a2x0 + b2x1 + c2x2 = d2 , Enter a2,b2,c2,d2:\n";
    cin >>a2>>b2>>c2>>d2;
}

void GaussSiedel::no_Iterate()
{

    cout << "Enter up to how much iteration do you want to go: ";
    cin >> num;
}
void GaussSiedel::calcX0()
{
    x0 = ( d0 - b0 * x1 - c0 * x2) /a0;
}

void GaussSiedel::calcX1()
{
    x1 = ( d1 - a1 * x0 - c1 * x2) /b1;
}

void GaussSiedel::calcX2()
{
    x2 = ( d2 - b2 * x1 - a2 * x0) / c2;
}

void GaussSiedel::solve()
{
    for(int i = 0;i<num;i++)
    {
        calcX0();
        calcX1();
        calcX2();

        cout << endl << endl <<"Iteration " << i+1 << ": \n";
        cout << "X0 = " << x0 << endl << "X1 = " << x1 << endl << "X2 = " << x2 ;
    }
}

int main()
{
    GaussSiedel g1;
    g1.askEqn();
    g1.no_Iterate();
    g1.solve();
    return 0;
}
