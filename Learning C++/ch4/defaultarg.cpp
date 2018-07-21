#include<iostream>
using namespace std;

int sum(int, int=0);
double power(double, int=2);
main()
{
  cout<<sum(2)<<sum(2,3);
  cout<<power(3,3)<<power(3,2);
}

int sum(int a, int b)
{
  return a+b;
}

double power(double a, int b)
{
  int product=1;
  for(int i=0;i<b;i++)
  product*=a;
}
