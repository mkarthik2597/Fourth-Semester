#include<iostream>
using namespace std;

class cls1
{
  int a;
public:
  cls1(){a=0; display();}
  cls1(int val)
  {
    a=val;
    display();
  }
  cls1(cls1& arg)
  {
    a=arg.a+1;
    display();
  }

  void display(void)
  {
    cout<<a<<endl;
  }
};

int main()
{
  cls1 A;
  cls1 B(10);
  cls1 C(B);
  cls1 D=C;
}
