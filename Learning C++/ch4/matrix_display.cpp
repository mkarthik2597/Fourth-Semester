#include<iostream>
using namespace std;
void display(int mat[][2],int,int);
main()
{
  int mat[2][2]={1,0,1,0};
  display(mat,2,2);
}

void display(int mat[][2], int m, int n)
{
  for(int row=0;row<2;row++)
  for(int col=0;col<2;col++)
  cout<<mat[row][col];
}
