#include<stdio.h>
int chopstick[5];
int philosopher[5];

#define UP 1
#define DOWN 0

#define THINK 0
#define HUNGRY 1
#define EAT 2

void eat(int);
void think(int);
int main()
{
  printf("Enter\n1 to change state to EAT\n2 to THINK\n3 to display states\n4 to exit:");
  int i;
repeat:
  scanf("%d",&i);
  int p;

  switch(i)
  {
    case 1: printf("Enter philosopher no:");
            scanf("%d",&p);
            eat(p);
            break;

    case 2: printf("Enter philosopher no:");
            scanf("%d",&p);
            think(p);

    case 3: ;
            int i;
            for(i=0;i<5;i++)
            {
              if(philosopher[i]==THINK)
              printf("%d->THINKING\n",i);

              else if(philosopher[i]==HUNGRY)
              printf("%d->HUNGRY\n",i);

              else
              printf("%d->EATING\n",i);
            }
  }

  if(i!=4)
  goto repeat;
}

void eat(int i)
{
  if(chopstick[i]==DOWN && chopstick[(i+1)%5]==DOWN)
  {
    chopstick[i]=chopstick[(i+1)%5]=UP;
    philosopher[i]=EAT;
    printf("Philosopher %d is EATING\n",i);
  }
  else
  {
    philosopher[i]=HUNGRY;
    printf("Philosopher %d is HUNGRY\n",i);
  }
}

void think(int i)
{
  chopstick[i]=chopstick[(i+1)%5]=DOWN;
  printf("Philosopher %d is THINKING\n",i);

  if(philosopher[(i-1)%5]==HUNGRY)
  eat((i-1)%5);
  if(philosopher[(i+1)%5]==HUNGRY)
  eat((i+1)%5);
}
