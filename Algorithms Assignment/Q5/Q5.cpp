#include <stdio.h>
#include <stdlib.h>
/*
Consider two sets A and B, each having n integers in the range from 0 to 10n. We wish

to compute the Cartesian sum of A and B, defined by
C = {x + y : x ∈ A, y ∈ B}.

Note that the integers in C are in the range 0 to 20n. We want to find the elements in C

and the number of times each element of C is realized as a sum of elements in A and B.

Show that the problem can be solved in O(n log n) time.
*/

static int track[100][100];
int n;
    int i,j,m;
    int p;
    int degreeA[100],degreeB[100];
    int coEffA[100],coEffB[100];
    int jA,jB;
 static int setA[1000],setB[1000];
    int setC[2000];
 int jC=0;
    int degreeC[2000];
    int coEffC[2000];
     int kl=0  ;
/*
int track=0;
void calculate(int trin,int ruhi)
{
int mid=(trin+ruhi)/2;
if(trin<ruhi)
{calculate(trin,mid);
calculate(mid+1,ruhi);
track=track+1;
printf("\t\t%d-track\n",track);
//problem(trin,ruhi);
}
else
{
printf("I am done!Bye!Goooo.... \n");
//exit(1);
}
return 0;
}
*/
void  calculate(int ruhi, int trin) {
   int mid;
 if(ruhi < trin) {
      mid = (ruhi + trin) / 2;
      calculate(ruhi, mid);
      calculate(mid+1, trin);
      problem(mid,ruhi,trin);
   } else {
      return;
   }
}


void problem (int mid,int ruhi,int trin)
{
int g;
 for(j=0;j<jA;j++)
     {
     //j=j-1;
     g=1;
     if(track[mid][j]!=-1)
     {m= (degreeB[mid] )+(degreeA[j] );
     g=g+(coEffA[j]+coEffB[mid]-2);
     setC[m]=setC[m]+g;
     track[mid][j] = -1;
     }
     //j=j+1;
     }
mid=ruhi;
 for(j=0;j<jA;j++)
     {
     //j=j-1;
     g=1;
     if(track[mid][j]!=-1)
     {m= (degreeB[mid] )+(degreeA[j] );
     g=g+(coEffA[j]+coEffB[mid]-2);
     setC[m]=setC[m]+g;
     track[mid][j] = -1;
     }
     //j=j+1;
     }

mid=trin;
 for(j=0;j<jA;j++)
     {
     //j=j-1;
     g=1;
     if(track[mid][j]!=-1)
     {m= (degreeB[mid] )+(degreeA[j] );
     g=g+(coEffA[j]+coEffB[mid]-2);
     setC[m]=setC[m]+g;
     track[mid][j] = -1;
     }
     //j=j+1;
     }

}


int main()
{

    printf("Enter the value of n\n");
    scanf("%d",&(n));

    for(i=0;i<2000;i++)
    {
      setC[i]=0;
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
    p= rand()%(10*n);
    setA[p]=setA[p]+1;
    }
    jA=0;
     for(i=0;i<20*n;i++)
    {
     if(setA[i]!=0)
     {//printf("%d\t%d\n",i,setA[i]);
     degreeA[jA]=i;
     coEffA[jA]=setA[i];
     jA=jA+1;
     }
    }

    /*for(i=0;i<jA;i++)
    {
    printf("%d\t%d\n",coEffA[i],degreeA[i]);
    }*/
    if(n>0)
    {
    printf("Set A has \t");
    for(i=0;i<jA;i++)
     {
      printf("%d \t",degreeA[i]);

     }
     printf("\n\n");
    for(i=0;i<jA;i++)
    {
    printf("No of times the number %d is repeated is %d\n",degreeA[i],coEffA[i]);
    }

    printf("\n\n");
    }


  jB=0;
     for(i=0;i<n;i++)
    {
    p= rand()%(10*n);
    setB[p]=setB[p]+1;

    }
printf("\n\n");
       for(i=0;i<20*n;i++)
    {
     if(setB[i]!=0)
     {//printf("%d\t%d\n",i,setA[i]);
     degreeB[jB]=i;
     coEffB[jB]=setB[i];
     jB=jB+1;
     }
    }

   // for(i=0;i<jB;i++)
   // {
   // printf("%d\t%d\n",coEffB[i],degreeB[i]);
   // }
   if(n>0)
   {
    printf("Set B has \t");
    for(i=0;i<jB;i++)
     {
      printf("%d \t",degreeB[i]);

     }
     printf("\n\n");
    for(i=0;i<jB;i++)
    {
    printf("No of times the number %d is repeated is %d\n",degreeB[i],coEffB[i]);
    }

    printf("\n\n");
   }
/*
    for(i=0;i<20*n;i++)
    {
     //if(setC[i]!=0)
     //{printf("%d\t%d\n",i,setC[i]);}
    }
*/
    printf("\n\n");
/*
    for(i=0;i<jB;i++)
    {
     for(j=0;j<jA;j++)
     {
     //j=j-1;
     m= (degreeA[i]*coEffA[i] )+(degreeB[j]*coEffB[j] );
     setC[m]=setC[m]+1;
     //j=j+1;
     }
    }

*/

if(n>1)
{
 calculate(0,jB-1);

         for(i=0;i<20*n;i++)
    {
     if(setC[i]!=0)
     {//printf("%d\t%d\n",i,setA[i]);
     degreeC[jC]=i;
     coEffC[jC]=setC[i];
     jC=jC+1;
     }
    }
printf("Set C has \t");
    for(i=0;i<jC;i++)
     {
      printf("%d \t",degreeC[i]);

     }
     printf("\n\n");
    for(i=0;i<jC;i++)
    {
    printf("No of times the number %d is repeated is %d\n",degreeC[i],coEffC[i]);
    }
}
else if(n==1)
{
degreeC[0]=degreeA[0]+degreeB[0];
printf("Set C has \t");
    for(i=0;i<1;i++)
     {
      printf("%d \t",degreeC[i]);

     }
     printf("\n\n");
    for(i=0;i<1;i++)
    {
    printf("No of times the number %d is repeated is %d\n",degreeC[i],1);
    }
}
else if(n<=0)
{
printf("All the sets are empty\n");
}

    printf("\n\n\n\n");
    return 0;
}
