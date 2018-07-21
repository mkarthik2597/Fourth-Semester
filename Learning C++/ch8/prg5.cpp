#include<iostream>
using namespace std;

class A
{
  int a;
public:
  A(int x){a=x;}
  A(){}
};

class B:public A
{
  int b;              //The constructor for class B is provided by the compiler
};

int main()
{
  B b1;
  cout<<"b1 is created\n";
}
