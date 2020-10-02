#include<stdio.h>
int main()
{
int n,time,remain=0,flag=0,time_quantum;
int wait_time[20],p[20],turnaround_time[20],at[10],bt[10],temp_bt[10];
printf("Enter Total  Number of Processes:\t ");
scanf("%d",&n);
remain=n;
for(int i=1;i<=n;i++)
{
printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i);
scanf("%d",&at[i]);
scanf("%d",&bt[i]);
p[i]=i;
temp_bt[i]=bt[i];
}
printf("Enter Time Quantum:\t");
scanf("%d",&time_quantum);
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
      }
    }
  }
  
for(int time=0,i=1;remain!=0;)
{
if(temp_bt[i]<=time_quantum && temp_bt[i]>0)
{
time+=temp_bt[i];
temp_bt[i]=0;
flag=1;
}
else if(temp_bt[i]>0)
{
temp_bt[i]-=time_quantum;
time+=time_quantum;
}
if(temp_bt[i]==0 && flag==1)
{
remain--;
wait_time[i]=(time-at[i])-bt[i];
turnaround_time[i]=time-at[i];
flag=0;
}
if(i==n+1)
i=0;
else if(at[i]<=time)
i++;
else
i=0;
}
//waiting Time
int sum_wait_time=0;
float avg_waitingT;
for(int i=1;i<=n;i++)
{
  sum_wait_time=sum_wait_time+wait_time[i];
}
avg_waitingT=sum_wait_time/n;
//Turn Around time
int sum_turnaround_time=0;
float avg_TurnaroundT;
for(int i=1;i<=n;i++)
{
  sum_turnaround_time=sum_turnaround_time+turnaround_time[i];
}
avg_TurnaroundT=sum_turnaround_time/n;

printf("\nProcess\tArrival Time\tBurt Time\tWaiting Time\tTurn Around Time\n");
for(int i=1;i<=n;i++)
{
  printf("P%d\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t\t%d\n",p[i],at[i],bt[i],wait_time[i],turnaround_time[i]);
}
printf("\nAverage Waiting Time :%f",avg_waitingT);
printf("\nAverage Turn Around Time :%f",avg_TurnaroundT);
return 0;
}
