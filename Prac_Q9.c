// (Non-Preemptive)Priority Scheduling
#include<stdio.h>
int tim=0;
void main()
{
  int n,b[20],w[20],taround[20],totaltime=0,totalwaiting=0,p[20],priority[20];
  float avg_waitingT,avg_time;
  printf("Enter the no of Processes=");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    printf("Enter the Burst Time of %dth Process :",i);
    scanf("%d",&b[i]);
    printf("Enter the Priority Of  %dth Process :",i);
    scanf("%d",&priority[i]);
    p[i]=i;

  }
  int temp;
  // Bubble Sorting
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n-i;j++)
    {
      if(priority[j]>priority[j+1])
      {
      //Sorting the Processes according to their Priorities 
      temp=priority[j];
      priority[j]=priority[j+1];
      priority[j+1]=temp;
      //Sorting the Buffer in accordance with its Priority
      temp=b[j];
      b[j]=b[j+1];
      b[j+1]=temp;
      //To Sort the Positions of Process in accordance with their Priority
      temp=p[j];
      p[j]=p[j+1];
      p[j+1]=temp;
      }
    }
  }
   for(int i=1;i<=n;i++)
  {
   w[i]=tim;   
    for(int j=1;j<=b[i];j++)
    {
      tim++;
      if(j==b[i])
      taround[i]=tim;
    }
  }
  for(int i=1;i<=n;i++)
  {
    totalwaiting=totalwaiting+w[i];
  }
  avg_waitingT=(float)totalwaiting/n;
 for(int i=1;i<=n;i++)
 {
   totaltime=totaltime+taround[i];
 }
 avg_time=(float)totaltime/n;
printf("\nProcess\tBurt Time\tPriority\tWaiting Time\tTurn Around Time\n");
for(int i=1;i<=n;i++)
{
  printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",p[i],b[i],priority[i],w[i],taround[i]);
}
printf("\nAverage Waiting Time :%f",avg_waitingT);
printf("\nAverage Turn Around Time :%f",avg_time);
}