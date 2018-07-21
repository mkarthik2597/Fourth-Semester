#include<stdio.h>
#define ABS(x) (x)>=0?(x):-(x)
#define RIGHT 1
#define LEFT -1

int main()
{
  int tot_cyl,curr_head,prev_head,N;

  printf("Enter: Total no. of cylinders, current head and previous head:");
  scanf("%d%d%d",&tot_cyl,&curr_head,&prev_head);

  printf("Enter total no. of requests:\n");
  scanf("%d",&N);

  int arr[N];

  insert_sort(arr,N);

  int flag=(prev_head<curr_head)?RIGHT:LEFT;
  int head;

  int sum=0,k;

  if(flag==RIGHT)
  {
    for(i=0;i<N;i++)
    {
      if(arr[i]>curr_head)
      {
        k=i;
        break;
      }
    }

    if(i==N)
    k=N-1;

    int count=0;

    printf("%d->%d %d\n",curr_head,arr[k],ABS(arr[k]-curr_head));
    count++;
    sum+=ABS(arr[k]-curr_head);

    if(i==N)
    {
      printf("%d->%d %d\n",arr[i-1],arr[i-2],ABS(arr[i-1]-arr[i-2]));
      i=N-2;
      count++;
      sum+=ABS(arr[i-1]-arr[i-2]);
    }

    while(count<N)
    {
      if(i+1>N-1)
      {
        printf("%d->%d %d\n",arr[i],arr[k-1],ABS(arr[i]-arr[k-1]));
        sum+=ABS(arr[i]-arr[k-1]);
        i=k-1;
        count++;
        continue;
      }

      if(i>=k)
      {
        printf("%d->%d %d\n",arr[i],arr[i+1],ABS(arr[i+1]-arr[i]));
        sum+=ABS(arr[i+1]-arr[i]);
        i++;
      }
      else
      {
        printf("%d->%d %d\n",arr[i],arr[i-1],ABS(arr[i]-arr[i-1]));
        sum+=ABS(arr[i]-arr[i-1]);
        i--;
      }

      count++;
    }

    printf("\nSum=%d\n",sum);
  }

  sum=0;

  if(flag==LEFT)
  {
    for(i=N-1;i>=0;i--)
    {
      if(arr[i]<curr_head)
      {
        k=i;
        break;
      }
    }

    if(i<0)
    k=0;

    int count=0;

    printf("%d->%d %d\n",curr_head,arr[k],ABS(arr[k]-curr_head));
    count++;
    sum+=ABS(arr[k]-curr_head);

    if(i==-1)
    {
      printf("%d->%d %d\n",arr[0],arr[1],ABS(arr[1]-arr[0]));
      i=1;
      count++;
      sum+=ABS(arr[i-1]-arr[i-2]);
    }

    while(count<N)
    {
      if(i-1<0)
      {
        printf("%d->%d %d\n",arr[i],arr[k+1],ABS(arr[i]-arr[k+1]));
        sum+=ABS(arr[i]-arr[k+1]);
        i=k+1;
        count++;
        continue;
      }

      if(i>k)
      {
        printf("%d->%d %d\n",arr[i],arr[i+1],ABS(arr[i+1]-arr[i]));
        sum+=ABS(arr[i+1]-arr[i]);
        i++;
      }
      else
      {
        printf("%d->%d %d\n",arr[i],arr[i-1],ABS(arr[i]-arr[i-1]));
        sum+=ABS(arr[i]-arr[i-1]);
        i--;
      }

      count++;
    }

    printf("\nSum=%d\n",sum);
  }
}

void inset_sort(int* arr, int N)
{
  int rqst;
  int i,j;

  printf("Enter your requests:");
  for(i=0;i<N;i++)
  {
    scanf("%d",&rqst);
    j=i-1;

    while(j>=0 && arr[j]>rqst)
    {
      arr[j+1]=arr[j];
      j--;
    }

    arr[j+1]=rqst;
  }
}
