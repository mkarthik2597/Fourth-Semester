#include<iostream>
using namespace std;

class cls1
{
  int a;
public:
  cls1(int b)
  {
    a=b;
  }
  cls1(){}
  void display()
  {
    cout<<a<<endl;
  }

  void operator+(cls1 A)
  {
    a=a+A.a;
  }
};

int main()
{
  cls1 a(2);
  a.display();

  cls1 b(3);
  b+a;
  b.display();
}
