#include<iostream>
using namespace std;

int area(int);
int area(int, int);
float area(double,double);
float area(double);

int gvalue=10;

int main()
{
  cout<<area(4)<<endl;
  cout<<area(1.2)<<endl;
  cout<<area(2,2)<<endl;
  cout<<area(1.2,2.0)<<endl;
}

inline int area(int a)
{
  return a*a;
}

inline int area(int a, int b)
{
  return a*b;
}

inline float area(double a)
{
  return 3.14*a*a;
}

inline float area(double a,double b)
{
  return 0.5*a*b;
}
