#include<iostream>
using namespace std;
int a[]={1,2,4,6,8,9};
int b[]={2,4,5,6,8,10,11};

int binary(int* a, int key, int low, int high )
{
  if(low==high)
    return low;
  int mid=(low+high)/2;
  if(key<a[mid])
    binary(a, key,low,mid);
  else if(key>a[mid])
    binary(a,key,mid+1,high);
  else if(key==a[mid])
    return mid;
}

int main()
{
    int i=0,j=0,pos,part;
    {
      for(int l=1;l<5;l++)
      if(a[i]<b[j])
      {
        i=binary(a,a[i]+1,i+1,6);
        pos=a[i];
      }
      else if(a[i]>b[j])
      {
        j=binary(b,b[j]+1,j+1,7);
        pos=b[j];
      }
      else
      {
        i=binary(a,a[i]+1,i+1,6);
        j=binary(b,b[j]+1,j+1,7);
        if(a[i]<b[j])
          pos=a[i];
        else
          pos=b[j];
      }
    }
  cout<<endl<<"Ans:"<<pos;
}
