#include<iostream>
using namespace std;

class A
{
  class B                       //class B is a nested class
  {
    int b;
  public:
    B(int x){b=x;}             //Paramterized constructor
    void display(){cout<<b<<endl;}
  };

  int a;
public:
  void createB(int x)
  {
    B b1(x);                  // An object of class B is created in a member function of class A
    b1.display();
  }
};

int main()
{
  A a1;
  a1.createB(5);

  B b1;              //This line generates error
}
