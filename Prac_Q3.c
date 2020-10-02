#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int a;
printf("\nKernel Version:\n");
system("cat /proc/sys/kernel/osrelease");
printf("\nInformation on Configured amount of free and Used Memory:\n");
system("cat /proc/meminfo | awk 'NR==1,NR==2 {print}'");
return 0;
}