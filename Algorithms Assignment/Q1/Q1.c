#include<stdio.h>

int kth_elem(int A[], int m, int B[], int n, int k, int p, int q)
{
    if (p > q)
    return kth_elem(B, n, A, m, k, 0, n-1);//search in B

    int i = p + (q - p) / 2;
    int j = k - 1 - i - 1;

    if ((j < 0 || (j < n && A[i] >= B[j])) && (j+1 >= n || (j+1 >= 0 && A[i] <= B[j+1])))
    {
        return A[i];
    }
    else if (j < 0 || (j+1 < n && A[i] > B[j+1]))
    {
        return kth_elem(A, m, B, n, k, p, i-1);
    } else
    {
        return kth_elem(A, m, B, n, k, i+1, q);
    }
}

int main()
{
	int A[100], B[100], m ,n;
	printf("Enter the sizes array sizes: ");
	scanf("%d %d", &m, &n);
	int i;
	printf("Enter elements of array A: ");
	for(i = 0; i<m; i++)
		scanf("%d", &A[i]);
	printf("Enter elements of array B: ");
		for(i = 0; i<n; i++)
			scanf("%d", &B[i]);
	int k;
	printf("Enter the value of k: ");
	scanf("%d", &k);

	printf("The %dth smallest element is: %d\n",k, kth_elem(A, m, B, n, k, 0, m+n));
}
