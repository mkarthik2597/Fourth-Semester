#include <iostream>
#include<cmath>
#define size 3

using namespace std;

main()
{
  int* arr= new int[size];
  int i,sum=0;
  cout<<"Enter any"<<size<<"values:";
  for(i=0;i<size;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }

  float avg=sum/float(size);
  cout<<"Average="<<avg;

  int temp=0;
  for(i=0;i<size;i++)
  {
    temp+=pow(arr[i]-avg,2);
  }

  cout<<"Variance="<<temp<<endl;
  cout<<"Standard deviation="<<sqrt(temp);

}
