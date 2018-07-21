#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void LIS(int a[], int n)
{

  vector< vector<int> > lis;
  // lis[i] denotes the longest increasing subsequence ending with a[i]
	// here make lis[0] a vector containing a[0]
  for(int i = 0; i<n; i++)
    lis.push_back({});
	lis[0].push_back(a[0]);

	//for every a[i], find the longest increasing subsequence ending with a[j]
	//for every element a[j] that comes before it and is less than a[i]
	// then append a[i] to it
	for(int i=1;i<n;i++)
  {
		for(int j=0;j<i;j++)
    {
				if(a[i]>a[j] && lis[j].size() >= lis[i].size())
				lis[i] = lis[j];
		}
		lis[i].push_back(a[i]);
	}
	// find the max among all lis[i]
	vector<int> max;
	max = lis[0];
	for(int i=1;i<n;i++){
		if(lis[i].size() > max.size())
			max = lis[i];
	}
	cout<<"Longest Increasing subsequence: ";
	for(int i=0;i<max.size();i++){
		cout<<max[i]<<" ";
	}
  cout<<"\n";
}

int main()
{
	cout<<"Enter no. of elements: ";
	int n;
	cin>>n;
  int a[n];

	cout<<"Enter Sequence : ";
	for(int i=0;i<n;i++)
    cin>>a[i];

	LIS(a, n);
	return 0;
}
