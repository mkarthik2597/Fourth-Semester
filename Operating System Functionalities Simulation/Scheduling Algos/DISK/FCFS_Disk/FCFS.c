#include<stdio.h>
#define ABS(x) (x)>0?(x):-(x)

int main()
{
  printf("Enter the no. of cylinders, current header position:");
  int tot_cyl,curr_head;
  scanf("%d%d",&tot_cyl,&curr_head);
  
  printf("Enter the no. of requests:");
  int N;
  scanf("%d",&N);
  int arr[N];
  
  printf("Enter the reqests:");
  int i;
  for(i=0;i<N;i++)
  scanf("%d",&arr[i]);
  
  int sum=0;
  printf("%d->%d %d\n",curr_head,arr[0],ABS(curr_head-arr[0]));
  sum+=ABS(curr_head-arr[0]);
  
  for(i=0;i<N-1;i++)
  {
    printf("%d->%d %d\n",arr[i],arr[i+1],ABS(arr[i]-arr[i+1]));
    sum+=ABS(arr[i]-arr[i+1]);
  } 
  
  printf("The total head movement=%d\n",sum);
}
  
