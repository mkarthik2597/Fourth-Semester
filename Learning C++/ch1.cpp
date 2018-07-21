#include<iostream>
#include<iomanip>

using namespace std;

class converter
{
  float celcius,fahrenheit;
public:
  float celtofar(float);
};

float converter::celtofar(float cel)
{
  return 9/5.0*cel+32;
}

int main()
{
  cout<<"Enter temperature in centigrade";
  float cel;
  cin>>cel;
  converter c1;
  int frn=c1.celtofar(cel);
  cout<<endl<<frn;
}
