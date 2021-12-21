#include <iostream>
#include<iomanip>
using namespace std;

float F(float x,float y){
  return (2*y)/x;
}

int main() {
  
  float x = 1,y = 2;
  float h = 0.25;

  cout<<"using heun's method"<<endl;

  cout<<"x"<<setw(10)<<"y"<<endl;
  cout<<x<<setw(10)<<y<<endl;;

  while(x<2){
    
    float xn = x + h;
    float euler = y + (h * F(x,y));

    y = y  + (h/2) * (F(x,y) + F(xn,euler));
    cout<<xn<<setw(10)<<y<<endl;
    x = x + h; 

  }

} 