#include<bits/stdc++.h>
using namespace std;
int A[100],B[100],C[100],i,k,n,temp[100],temp2[100];
int partition(int arr[], int l, int r, int k);

// A simple function to find median of arr[].  This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthSmallest(arr, l, pos-1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void findResult()
{
	int med,q,j,i,pos = -1;
	for(i=0;i<n;++i)
  {
		temp[i] = A[i];
	}
	med=kthSmallest(A,0,n-1,(n+1)/2);   //finds the median
	for(i=0;i<n;++i)
  {
		A[i] = temp[i];
		if(temp[i] == med)
    {
			pos = i;
		}
	}
	for(i=0;i<n;++i)
  {
	   B[i]=abs(A[i]-med);
	}
	cout<<"\n";
	for(i=0;i<n;++i){
		temp2[i] = B[i];
	}
	q=kthSmallest(B,0,n-1,k+1); //get the kth smallest difference
	for(i=0;i<n;++i){
		B[i] = temp2[i];
	}
	cout<<k<<" closest elements to median "<<med<<" are :\n";
	j=0;
	for(i=0;i<n;++i){
	   if(B[i]<q && pos != i && j<k){
	     C[j]=A[i];//A[i], the real value should be assigned instead of B[i] which is only the difference between A[i] and median.
	   	 cout<<C[j]<<" ";
	     j++;
	   }
	}
	for(i=0;i<n;++i){
	   if(B[i]==q && pos != i && j<k){
	     C[j]=A[i];//A[i], the real value should be assigned instead of B[i] which is only the difference between A[i] and median.
	   	 cout<<C[j]<<" ";
	     j++;
	   }
	}
	cout<<"\n";
}
// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main()
{
	cout<<"\nEnter size of your array:";
	cin>>n;
  cout<<"Enter the elements of your array:";
	for(i=0;i<n;++i)
  {
		cin>>A[i];
	}
	cout<<"\nEnter the value of k : ";
	cin>>k;
	if(k<=0) cout<<"\ninvalid!\n",exit(0);
	findResult();
	// cout<<"\nElement : "<<kthSmallest(A,0,n-1,k);

}
