#include<iostream>
using namespace std;

class A
{
  int a;
public:
  A(int x){a=x;}
  friend void operator=(int,A);
};

void operator=(int x,A a1)
{
  a1.a=x;
  cout<<"Done"
}

int main()
{
  A a1(10);
  7=a1;
}
