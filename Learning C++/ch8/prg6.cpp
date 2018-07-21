#include<iostream>
using namespace std;

class A
{
  int a;
public:
  A(int x)
  {
    a=x;
    cout<<"class A"<<endl;
  }
};

class B:public A
{
public:
  B()
  {
    A(3);
  }
};

int main()
{
  B b1;
}
