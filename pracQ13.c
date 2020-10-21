//First Fit,Best Fit and Worst Fit Allocations 
#include<stdio.h>
void display(int a1[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("  %d",a1[i]);
  }
}


//First Fit Allocation
void firstfit(int no_Process,int no_Mem,int Mem_Space[],int Proc_Spac[])
{
  int temp_mem[30]={0};
  //To store the value of Memory space in temporary variable
  for(int j=0;j<no_Mem;j++)
  {
    temp_mem[j]=Mem_Space[j];
  }
  printf("----------------First Fit Allocation----------------\n");
  printf("Process\n");
  display(Proc_Spac,no_Process);
  printf("\nMemory\n");
  display(Mem_Space,no_Mem);
  printf("\n");
  
  int i,j,flag[30]={0},in_Frag=0,ex_Frag=0;
  //For Internal Fragmentation
  for(i=0;i<no_Process;i++)
  {
    for(j=0;j<no_Mem;j++)
    {
      if(Mem_Space[j]>=Proc_Spac[i])
      {
        flag[j]=1;
        in_Frag=in_Frag+(Mem_Space[j]-Proc_Spac[i]);
        Mem_Space[j]=Mem_Space[j]-Proc_Spac[i];
        break;
      }
    }
    if(j==no_Mem)
    {
      printf("No More Space Left For Process\n");
    }
  }
  //For External Fragmentation
  for(int j=0;j<no_Mem;j++)
    {
      if(flag[j]==0)
      {
        ex_Frag=ex_Frag+Mem_Space[j];
      }
    } 
    printf("Total of Internal Fragmentation :%d\n",in_Frag);
    printf("Total of External Fragmentation :%d\n",ex_Frag);
  //To Store back the original value of memory space  
  for(int j=0;j<no_Mem;j++)
  {
    Mem_Space[j]=temp_mem[j];
  }
}

//Best Fit Allocation
void bestfit(int no_Process,int no_Mem,int Mem_Space1[],int Proc_Spac1[])
{
  printf("----------------Best Fit Allocation----------------\n");
  printf("Process\n");
  display(Proc_Spac1,no_Process);
  printf("\nMemory\n");
  display(Mem_Space1,no_Mem);
  printf("\n");
  int temp_mem1[30]={0},temp;
  //To store the value of Memory space in temporary variable
  for(int j=0;j<no_Mem;j++)
  {
    temp_mem1[j]=Mem_Space1[j];
  }
  // Bubble Sorting
  for(int i=0;i<no_Mem;i++)
  {
    for(int j=0;j<no_Mem-i-1;j++)
    {
      if(Mem_Space1[j]>Mem_Space1[j+1])
      {
      //Sorting the Memory Space in ascending order
      temp=Mem_Space1[j];
      Mem_Space1[j]=Mem_Space1[j+1];
      Mem_Space1[j+1]=temp;
      }
    }
  }
  //Applying the Alogrithm
  int i,j,flag[30]={0},in_Frag1=0,ex_Frag1=0;
  //For Internal Fragmentation
  for(i=0;i<no_Process;i++)
  {
    for(j=0;j<no_Mem;j++)
    {
      if(Mem_Space1[j]>=Proc_Spac1[i])
      {
        flag[j]=1;
        in_Frag1=in_Frag1+(Mem_Space1[j]-Proc_Spac1[i]);
        Mem_Space1[j]=Mem_Space1[j]-Proc_Spac1[i];
        break;
      }
    }
    if(j==no_Mem+1)
    {
      printf("No More Space Left For Process\n");
    }
  }
  //For External Fragmentation
  for(int j=0;j<no_Mem;j++)
    {
      if(flag[j]==0)
      {
        ex_Frag1=ex_Frag1+Mem_Space1[j];
      }
    }
    
    printf("Total of Internal Fragmentation :%d\n",in_Frag1);
    printf("Total of External Fragmentation :%d\n",ex_Frag1);
  //To Store back the original value of memory space  
  for(int j=0;j<no_Mem;j++)
  {
    Mem_Space1[j]=temp_mem1[j];
  }
}

//Worst Fit Allocation Method
void worstfit(int no_Process,int no_Mem,int Mem_Space2[],int Proc_Spac2[])
{
  printf("----------------Worst Fit Allocation----------------\n");
  printf("Process\n");
  display(Proc_Spac2,no_Process);
  printf("\nMemory\n");
  display(Mem_Space2,no_Mem);
  printf("\n");
  int temp_mem2[30]={0},temp;
  //To store the value of Memory space in temporary variable
  for(int j=0;j<no_Mem;j++)
  {
    temp_mem2[j]=Mem_Space2[j];
  }
  // Bubble Sorting method
  for(int i=0;i<no_Mem;i++)
  {
    for(int j=0;j<no_Mem-i-1;j++)
    {
      if(Mem_Space2[j]<Mem_Space2[j+1])
      {
      //Sorting the Memory Space in Descending order
      temp=Mem_Space2[j];
      Mem_Space2[j]=Mem_Space2[j+1];
      Mem_Space2[j+1]=temp;
      }
    }
  }
  
  //Applying the Alogrithm
  int i,j,flag[30]={0},in_Frag1=0,ex_Frag1=0;
  //For Internal Fragmentation
  for(i=0;i<no_Process;i++)
  {
    for(j=0;j<no_Mem;j++)
    {
      if(Mem_Space2[j]>=Proc_Spac2[i])
      {
        flag[j]=1;
        in_Frag1=in_Frag1+(Mem_Space2[j]-Proc_Spac2[i]);
        Mem_Space2[j]=Mem_Space2[j]-Proc_Spac2[i];
        break;
      }
    }
    if(j==no_Mem+1)
    {
      printf("No More Space Left For Process\n");
    }
  }
  //For External Fragmentation
  for(int j=0;j<no_Mem;j++)
    {
      if(flag[j]==0)
      {
        ex_Frag1=ex_Frag1+Mem_Space2[j];
      }
    }
    
    printf("Total of Internal Fragmentation :%d\n",in_Frag1);
    printf("Total of External Fragmentation :%d\n",ex_Frag1);
  //To Store back the original value of memory space  
  for(int j=0;j<no_Mem;j++)
  {
    Mem_Space2[j]=temp_mem2[j];
  }
}
int main()
{
  int ch,mem_array[30],pro_array[30],no_memory,no_process;
  //Memory Space
  printf("Enter the no of memory available :");
  scanf("%d",&no_memory);
  printf("Enter the Memory Space in the Array :\n");
  for(int i=0;i<no_memory;i++)
  {
    scanf("%d",&mem_array[i]);
  }
  
  //Processes
  printf("Enter the no of Process available :");
  scanf("%d",&no_process);
  printf("Enter the Process Space in the Array :\n");
  for(int i=0;i<no_process;i++)
  {
    scanf("%d",&pro_array[i]);
  }
  do
  {
    printf("\n------------------Menu-----------------\n");
    printf("\n1.For First Fit\n2.For Best Fit\n3.For Worst Fit \n4.To Exit");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      firstfit(no_process,no_memory,mem_array,pro_array);
      break;
      case 2:
      bestfit(no_process,no_memory,mem_array,pro_array);
      break;
      case 3:
      worstfit(no_process,no_memory,mem_array,pro_array);
      break;
    }
  }while(ch!=4);
return 0;
}