#include<stdio.h>
#define RIGHT 1
#define LEFT -1
#define ABS(x) (x)>0?(x):-(x)

int DIR;
int count;

void insert_sort(int*, int);
int Locate_Nearest_Head(int*,int,int);
int RMOVE(int* ,int, int, int);
int LMOVE(int* ,int, int, int);

int main()
{
  printf("Enter total no. of cylinders, current head:");
  int tot_cyl,curr_head;
  scanf("%d%d",&tot_cyl,&curr_head);
  
  printf("Enter total no. of requests:");
  int N;
  scanf("%d",&N);
  
  int arr[N];
  
  insert_sort(arr,N);
  
  int loc=Locate_Nearest_Head(arr,N,curr_head);
  
  int sum=0;
  printf("%d->%d %d\n",curr_head,arr[loc],ABS(curr_head-arr[loc]));
  count++;
  sum+=ABS(curr_head-arr[loc]);
  
  if(DIR==RIGHT)
  {
    sum+=RMOVE(arr,N,loc,tot_cyl);
    printf("Total moves=%d\n",sum);
  }
  else
  {
    sum+=LMOVE(arr,N,loc,tot_cyl);
    printf("Total moves=%d\n",sum);
  }
  
}

void insert_sort(int* arr, int N)
{
  printf("Enter the requests:");
  int i,j,x;
  
  for(i=0;i<N;i++)
  {
    scanf("%d",&x);
    j=i-1;
    
    while(j>=0 && arr[j]>x)
    {
      arr[j+1]=arr[j];
      j--;
    }
    
    arr[j+1]=x;
  }
}

int Locate_Nearest_Head(int* arr, int N, int curr_head)
{
  if(arr[0]>curr_head)
  {
    DIR=RIGHT;
    return 0;
  }
  
  if(arr[N-1]<curr_head)
  {
    DIR=LEFT;
    return N-1;
  }
  
  int i;
  for(i=1;i<N;i++)
  {
    if(arr[i]>curr_head)
    {
      if(arr[i]-curr_head <= curr_head-arr[i-1])
      {
        DIR=RIGHT;
        return i;
      }
      else
      {
        DIR=LEFT;
        return i-1;
      }
    }
  }
}

int RMOVE(int* arr, int N, int loc, int tot_cyl) 
{
  int i=loc;
  int sum=0;
  
  while(count<N)
  {
    if(i==N-1)
    {
      printf("%d->%d %d\n",arr[N-1],tot_cyl-1,tot_cyl-arr[N-1]-1);
      sum+=tot_cyl-arr[N-1];
      
      i=0;
      
      printf("%d->%d %d\n",tot_cyl-1,0,0);
      printf("%d->%d %d\n",0,arr[0],tot_cyl-arr[0]);
      sum+=tot_cyl-arr[0];
      count++;
    }
    
    printf("%d->%d %d\n",arr[i],arr[i+1],arr[i+1]-arr[i]);
    sum+=arr[i+1]-arr[i];
    count++;
    i++;
  }
  
  return sum;
}

int LMOVE(int* arr, int N, int loc, int tot_cyl)
{
  int i=loc;
  int sum=0;
  
  while(count<N)
  {
    if(i==0)
    {
      printf("%d->%d %d\n",arr[0],0,arr[0]-0);
      sum+=arr[0]-0;
      
      i=N-1;
      
      printf("%d->%d %d\n",0,tot_cyl-1,0);
      printf("%d->%d %d\n",tot_cyl-1,arr[N-1],arr[N-1]);
      sum+=arr[N-1];
      count++;
    }
    
    printf("%d->%d %d\n",arr[i],arr[i-1],arr[i]-arr[i-1]);
    sum+=arr[i]-arr[i-1];
    count++;
    i--;
  }
  
  return sum;
}
      

