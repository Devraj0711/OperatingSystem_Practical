#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc,char *argv[3])
{
int i;
struct stat buffer;
printf("GIve File Name:");
for(i=1;i<argc;i++)
{
printf("file=%s\n",argv[i]);
if(stat(argv[i],&buffer)<0)
printf("Error in File Started");
else
{
printf("Ownered=%d\ngid=%d\n",buffer.st_uid,buffer.st_gid);
printf("Access Permission=%d\n",buffer.st_mode);
printf("Access Time=%ld\n",(time(&(buffer.st_atime))));
}
}
}