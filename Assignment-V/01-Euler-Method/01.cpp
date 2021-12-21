#include <iostream>
#include<iomanip>
using namespace std;

float F(float x,float y){
  return (float)(2*y)/x;
}

int main() {
  
  float x = 1,y=2;
  float h = 0.25;

  cout<<"using eulers method "<<endl;
  cout<<"x"<<setw(10)<<"y"<<endl<<endl;
  cout<<x<<setw(10)<<y<<endl;

  while(x<=1.75){

     y = y + (h * F(x,y));
      x = x + h;
    cout<<x<<setw(10)<<y<<endl;

  }


} 