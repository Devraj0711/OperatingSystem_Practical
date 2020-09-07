#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
  int a;
  a=fork();
  if(a<0)
  {
    printf("Fork failed");
  }
  else if(a==0)
  {
    printf("\nChild Executed :\n ParentId : %d\nChild Id :%d",getppid(),getpid());
    
  }
  else
  {
    wait(NULL);
    printf("\nParent  Executed :%d",getpid());
  }
  return 0;
}