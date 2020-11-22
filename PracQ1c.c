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
    printf("\nChild Executing");
    execlp("Q4c","ls",NULL );
  }
  else
  {
    wait(NULL);
    printf("\nParent  Executing :%d",getpid());
  }
  return 0;
}
