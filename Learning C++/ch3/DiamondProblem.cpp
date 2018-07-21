#include<iostream>
using namespace std;

class GP
{
public:
  int a;
  void display(){cout<<a<<endl;}
};

class P1:public GP
{

};

class P2: public GP
{

};

class child:public P1, public P2
{

};

int main()
{
  child ch1;
  cout<<sizeof(ch1)<<endl;  //Output is 8
  ch1.P1::a=10;             //ch1.a=10 will give an ambiguity error
  ch1.P1::display();        // Similarly, ch1.display() gives an ambiguity error

}
