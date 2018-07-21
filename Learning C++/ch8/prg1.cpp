#include<iostream>
using namespace std;

class A
{
  int a;
public:
  int a_p;
  void displayA()
  {
    cout<<"A::a "<<a<<endl;
  }
  void displayAP()
  {
    cout<<"A::a_p "<<a_p<<endl;
  }
  void get_a(int x)
  {
    a=x;
  }
};

class B:public A
{
  int b;
public:
  void displayB()
  {
    cout<<"A::a_p "<<a_p<<endl;
  }
};

int main()
{
  B b1,b2;
  b1.get_a(5);
  b2.get_a(10);

  b1.displayA();
  b2.displayA();

  cout<<"......"<<endl;

  b1.a_p=25;
  b1.displayB();
  b1.displayAP();
}
