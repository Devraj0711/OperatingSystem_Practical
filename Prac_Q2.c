#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int a;
printf("\nKernel Version:\n");
system("cat /proc/sys/kernel/osrelease");
printf("\nCPU TYPE & MODEL:\n");
system("cat /proc/cpuinfo | awk 'NR==4,NR==5 {print}'");
return 0;
}