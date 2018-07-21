#include<bits/stdc++.h>
using namespace std;

/*Returns the number of occurrences of "ele" in A[l..h]*/
int getFreq(int *A, int l, int h, int ele)
{
  int count = 0;
  for(int i=l;i<h;i++)
    if(A[i]==ele)
      count++;
  return count;
}

int findMax(int *A,int l, int h)
{
  /*Base case*/
  if((h-l)==1)
    return A[l];

  /*k stores n/2, n being the number of elements in A[l]..A[h]*/
  int k = (int)(h-l)/2;
  /*Find majority element in left half of array and store it in left*/
  int left = findMax(A, l, l + k);
  /*Find majority element in left half of array and store it in left*/
  int right = findMax(A, l + k, h);
  /*If both the left and right halves have same majority, return it*/
  if(left==right)
    return left;
  /* Else, count the frequency of elements left and right in the entire array*/
  int lcount = getFreq(A, l, h, left);
  int rcount = getFreq(A, l, h, right);

  /*If either of them form a majority, return it*/
  if(lcount>k)
    return left;
  if(rcount>k)
    return right;

  /*If none of the above conditions hold, there is no majority element*/
  return INT_MIN;
}

int main()
{
  int n;
  cout<<"\nEnter your array size: ";
  cin>>n;
  int *A = new int[n];
  cout<<"\nEnter the elements :";
  for(int i=0;i<n;i++)
    cin>>A[i];
  int max = findMax(A, 0, n);
  if(max==INT_MIN)
    cout<<"\nThere is no majority element in the array.";
  else
    cout<<"\nThe majority element in the array is :"<<max<<".\n";
  return 1;
}
