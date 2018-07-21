#include<bits/stdc++.h>
#include<climits>
using namespace std;


int findMax(int *A,int n)
{
  if(n==0)
    return INT_MIN;
  else if(n==1)
    return A[0];
  else if(n==2)
  {
    if(A[0]==A[1])
      return A[0];
    else
      return INT_MIN;
  }
  int *temp = new int[n];
  int j=0;
  for(int i=0;i<n-1;i+=2)
    if(A[i]==A[i+1])
      temp[j++] = A[i];
  if(n%2==1)
    if(A[n-1]==A[0])
      temp[j++] = A[0];

  // for(int i=0;i<j;i++)
  //   cout<<temp[j]<<"  ";
  return findMax(temp, j);

}

int main()
{
  int n, count=0;
  cout<<"\nEnter the number of elements : ";
  cin>>n;
  int *A = new int[n];
  cout<<"\nEnter the elements :";
  for(int i=0;i<n;i++)
    cin>>A[i];
  int max = findMax(A, n);
  for(int i=0;i<n;i++)
    if(A[i]==max)
      count++;
  if(count<=n/2)
  max = INT_MIN;
  if(max==INT_MIN)
    cout<<"\nThe array doesnt have an maximum element.";
  else
    cout<<"\nThe maximum element in the array is :"<<max<<".\n";
  return 1;
}
