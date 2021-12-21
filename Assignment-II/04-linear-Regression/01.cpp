#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cout<<"Enter the number of values:";
	cin>>n;
	float x[n],y[n],m,c,x_mean,y_mean;
	float x_sum=0.0, y_sum=0.0, xy_sum=0.0, x2_sum=0.0;
	cout<<"Enter the values for x:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter x["<<i<<"]";
		cin>>x[i];
		x_sum=x_sum + x[i];
		x2_sum = x2_sum + (x[i]*x[i]);
	}
	x_mean = x_sum / n;
	cout<<"Enter the values for y:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter y["<<i<<"]";
		cin>>y[i];
		y_sum = y_sum + y[i];
		xy_sum = xy_sum + (x[i]*y[i]);
	}
	y_mean = y_sum / n;
	m = (n*xy_sum-(x_sum*y_sum)) / (n*x2_sum - (x_sum*x_sum));
	c = y_mean - (m*x_mean);
	cout<<endl;
	cout<<"The required eqn is y = "<<m<<" x + "<< c<<endl;
	float pred;
	cout<<"Enter the value of x to predict:";
	cin>>pred;
	cout<<"The predicted value for y is: "<<m*pred+c;
}