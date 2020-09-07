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
  else
  {
    printf("parent and child executed :%d",getpid());
  }
  return 0;
}