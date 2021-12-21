#include<iostream>
#include<math.h>
using namespace std;
class Cubic_Spline{
	float a[20];
	float h[20];
	float s[20];
	float x[20];
	float y[20];
	float u[20];
	int n;
	float xx;
	public:
		void getN()
		{
			cout << "Enter the number of data: ";
			cin >> n;
		}
		void getXX()
		{
			// cout << "Enter x:";
			cout << "Enter the value to be interpolted: ";
			cin >> xx;
		}
		void getX()
		{
			// cout << "Enter the values for x:"<<endl;
			// for(int i=0; i<n; i++)
			// {
			// 	cout << "Enter x["<<i<<"]:";
			// 	cin >> x[i];
			// }


			cout<<"Enter the value of x and fx: \n";
			cout<<"x   fx\n";
			for (int i = 0; i < n; i++) {
				cin>>*(x + i)>>y[i];
			}
		}
		void getY()
		{
			cout << "Enter the values for f(x): "<<endl;
			for(int i=0; i<n; i++)
			{
				cout << "Enter fx["<<i<<"]:";
				cin >> y[i];
			}
		}
		void getU()
		{
			for(int i=0; i<n; i++)
			{
				u[i] = xx - x[i];
				// cout << "u[" << i << "] = " << u[i] << endl;
			}
		}
		void getH()
		{
			for(int i=1; i<n; i++)
			{
				h[i] = x[i] - x[i-1];
				// cout << "H[" << i << "] = " << h[i] << endl;
			}
		}
		void getA()
		{
			for(int i = 1; i < n-1; i++)
    		{
        		a[i] = ( 6*( (y[i+1]-y[i])/h[i+1] -  (y[i]-y[i-1])/h[i]  )  -  h[i]*a[i-1]  -  h[i+1]*a[i+1]  ) / (2*( h[i] + h[i+1] ));
				// cout << "A[" << i << "] = " << a[i] << endl;
    		}
		}
		void getS()
		{
			int k;
    		for(int i = 1; i < n; i++)
    		{
        		if(xx>=x[i-1]&& xx<=x[i]){
        		s[i] =  a[i-1]/(6*h[i]) * ( pow(h[i],2)*u[i] - pow(u[i],2) )  +  a[i]/(6*h[i]) * ( pow(u[i-1],3)  - pow(h[i],2)*u[i-1]  )   +  1/h[i] * (y[i]*u[i-1]  -  y[i-1]*u[i]);
        		k = i;
				// cout << "S[" << i << "] = " << s[i] << endl;
    		}
    		}
			cout<<"Value at "<< xx << " using Cubic Splines Interpolation is "<<s[k] <<endl;
    		// cout << "s "<< s[k]<<endl<<endl;
		}
		void getAll()
		{
			getN();
			getX();
			// getY();
			getXX();
			a[0]=0;
			a[n-1]=0;
		}
		void solveAll()
		{
			getH();
			getU();
			getA();
			getS();
		}
};
int main()
{
	Cubic_Spline c1;
	c1.getAll();
	c1.solveAll();
}