#include<iostream>
using namespace std;

class A
{
  int a;
public:
  void display(){cout<<"A"<<endl;}
};

class B:public A
{
  // A::a, inaccessible
  int b;
public:
  // A::display()
  void display(){cout<<"B"<<endl;}
};

class C: public A,public B
{
  // int a, inaccessible;
  // int b, inacessible;
  //int c;
//public:
  //void B::display(){cout<<"B"<<endl;}
  //void A::B::display(){cout<<"A"<<endl;}  // The inherited display function in class B
};

int main()
{
  B b1;
   cout<<sizeof(A)<<endl<<sizeof(B)<<endl<<sizeof(C)<<endl;
  b1.display();
  // C c1;
  // c1.display();

  //c1.display();
}
