#include<iostream>
using namespace std;

class A
{
  int a;
public:
  static int b;
  static void showb(){cout<<b<<endl;}
};

class B:public A
{};

int A::b=2;
int main()
{
  B::showb();
  // A obj1;
  // obj1.b=3;
  // //A::showb();
  // //obj1.showb();
  // cout<<B::b<<endl;

}
