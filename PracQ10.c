//Preemptive Priority Scheduling
#include<stdio.h>
int main()
{
  int n,p[30],bt[30],temp_bt[30],wt[30],tat[30],at[30],priority[30],smallest=0,time,remain;
  float avg_waitingT,avg_turnaroundT;
  printf("Enter the Number of Processes :");
  scanf("%d",&n);
  remain=n;
  for(int i=1;i<=n;i++)
  {
    printf("Enter the Burst Time of Process %d :",i);
    scanf("%d",&bt[i]);
    printf("Enter the Arrival time for Process %d :",i);
    scanf("%d",&at[i]);
    printf("Enter the Priority for the Process %d :",i);
    scanf("%d",&priority[i]);
    temp_bt[i]=bt[i];
    p[i]=i;
  }
  int temp;
  // Bubble Sorting
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n-i;j++)
    {
      if(at[j]>at[j+1])
      {
      //Sorting the Processes according to their Arrival Time
      temp=at[j];
      at[j]=at[j+1];
      at[j+1]=temp;
      //Sorting the Buffer in accordance with its Arrival Time
      temp=bt[j];
      bt[j]=bt[j+1];
      bt[j+1]=temp;
      //To Sort the Positions of Process in accordance with their Arrival Time
      temp=p[j];
      p[j]=p[j+1];
      p[j+1]=temp;
      //sorting the Priority of the Process in accordance with their Arrival time
      temp=priority[j];
      priority[j]=priority[j+1];
      priority[j+1]=temp;
      }
    }
  }
priority[29]=45;
for(time=0;remain!=0;time++)
{
  smallest=29;
  for(int i=1;i<=n;i++)
  {
    if(at[i]<=time &&priority[i]<priority[smallest]&&temp_bt[i]>0)
    {
      smallest=i;
    }
  }
  temp_bt[smallest]--;
  if(temp_bt[smallest]==0)
  {
    remain--;
    tat[smallest]=time+1-at[smallest];
    wt[smallest]=tat[smallest]-bt[smallest];
  }
}
int total_wt=0,total_tat=0;
for(int i=1;i<=n;i++)
{
total_wt=total_wt+wt[i];
total_tat=total_tat+tat[i];
}
avg_waitingT=total_wt/n;
avg_turnaroundT=total_tat/n;
printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnAround Time\n");
for(int i=1;i<=n;i++)
{
printf("\nP%d\t\t%d\t\t \t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d",p[i],at[i],bt[i],priority[i],wt[i],tat[i]);
}
printf("\nAverage Waiting time : %f\n",avg_waitingT);
printf("Average Turn Around Time :%f",avg_turnaroundT);
return 0;
}
