#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
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
    printf("\nChild Executed : \n ParentId :%d\nChild Id : %d",getppid(),getpid());
  }
  else
  {
    printf("Parent  Executed :%d",getpid());
  }
  return 0;
}