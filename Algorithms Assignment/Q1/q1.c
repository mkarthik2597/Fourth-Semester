#include<stdio.h>
#define min(a,b) a > b ? b:a
  
int findKthSmallestElement(int a[], int b[], int sizeA, int sizeB, int k){
  /* to maintain uniformity, we will assume that 
     size_a is smaller than size_b
  else we will swap array in call*/
  if(sizeA > sizeB)
    return findKthSmallestElement(b, a, sizeB, sizeA, k);
  /* Now case when size of smaller array is 0 
     i.e there is no elemt in one array*/
  if(sizeA == 0 && sizeB >0)
    return b[k-1]; // due to zero based index
  
  /* case where K ==1 that means we have hit limit */
  if(k ==1)
    return min(a[0], b[0]);
  
  /* Now the divide and conquer part */
  int i =  min(sizeA, k/2) ; // K should be less than the size of array  
  int j =  min(sizeB, k/2) ; // K should be less than the size of array  
  
  if(a[i-1] > b[j-1])
    // Now we need to find only K-j th element
    return findKthSmallestElement(a, b+j, sizeA, (sizeB-j), k-j);
  else
    return findKthSmallestElement(a+i, b, (sizeA-i), sizeB, k-i);
  
  return -1;
}
int main()
{
    int a[10],b[10],i,n,k,m;
    printf("Enter the value of m(no of elements in array1)\n");
    scanf("%d",&m);
    printf("Enter the value of n(no of elements in array2)\n");
    scanf("%d",&n);
    printf("Enter the elements of array 1 in sorted form\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of array 2 in sorted form\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("Enter the k value to search for kth small element in the union\n");
    scanf("%d",&k);
    printf("\n Kth smallest element is : %d\n", 
             findKthSmallestElement(a,b,m,n, k));
    
}   
