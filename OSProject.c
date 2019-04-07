#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/queue.h>
struct process
{
    int pid;           //process id
    float AT;          //arrival time
    float BT;          //burst time
    float BT1;         //to save burst time
    float WT;          // waiting time 
    float priority;    //priority
    int status;        /* status 0 : not available
                          status 1 : ready
                          status 2 : processed */
    float TT;          //turnaround time
};

int main()
{
    int k;
    float TBT=0;  //total burst time
    float CT=0;   //completion time
    float TTT=0;  //total turnaround time
    float TWT=0;  //total waiting time
    float AWT;
    float ATT;
    int prior;
    int h=0;
    int min_bt;
    int j=0;
    printf("\n\n\n Enter The No. Of Processes You Want To Schedule : ");
    int number;
    scanf("%d",&number);
    int v[number];
    struct process proc[number];



    
    printf("\n Enter The Burst Time Of The Processes \n");
 
    for(int i=0;i<number;i++)
    {
        printf("\n Enter The Burst Time For The Process %d  :  ",i+1);
        scanf("%f",&proc[i].BT);
        proc[i].BT1=proc[i].BT;
        proc[i].pid=i+1;
        v[i]=0;
        proc[i].status=0;
    }





    printf("\n Enter The Arrival Time Of The Processes\n");
    for(int i=0;i<number;i++)
    {
        printf("\n Enter The Arrival Time For The Process %d  :  ",i+1);
        scanf("%f",&proc[i].AT);
    }
     
    printf("\n\nProcess                                Burst Time                                 Arrival Time\n");
    for(int i=0;i<number;i++)
    {
        printf("%d                                        %.2f                                         %.2f\n",proc[i].pid,proc[i].BT,proc[i].AT);
    }

    

    // Main Section
    int min_at=proc[0].AT;
    int max_at=proc[0].AT;
    for(int i=1;i<number;i++)
    {
        proc[i].WT=0;
        if(proc[i].AT<min_at)
          min_at=proc[i].AT;
        if(proc[i].AT>max_at)
          max_at=proc[i].AT;
    }


    for(int i=0;i<number;i++)
        TBT=TBT+proc[i].BT;
    CT=min_at+TBT;

    X:
    if(min_at<=max_at)
    {
    for(int i=0;i<number;i++)
    {
        if(proc[i].AT==min_at)
        {
            proc[i].status=1;
        }
    } 
    }





    if(h==0)
    {
        int c=0;
    for(int i=0;i<number;i++)
    {
    if(proc[i].status==1)
    {
        if(c==0)
         {            
        min_bt=proc[i].BT;
        c++;
         }
        if(min_bt>proc[i].BT)
            min_bt=proc[i].BT;
    }
    }
    }
     



    for(int i=0;i<number;i++) 
    {
    if(proc[i].status==1)
    {
        proc[i].priority=1+(proc[i].WT/proc[i].BT);
        if(h==0)
         {
            for(int i=0;i<number;i++)
            {
                if(min_bt>proc[i].BT)
                {
                    min_bt=proc[i].BT;
                    prior=i;
                }

            }

        }
        else
        {
            if(j!=  (number-1));
            {
        if(proc[i].priority>proc[prior].priority)
            prior=i;
            }
        }   
    }
    } 
     

    h=h+1;
    for(int i=0;i<number;i++)
    {
        if(proc[i].status==1)
        {   
            if(j==(number-1))
            {
                proc[i].BT=proc[i].BT-1;
            }
            else
            {
            if(i==prior)
                proc[i].BT=proc[i].BT-1;
            else
                proc[i].WT=proc[i].WT+1;
            } 
            if(v[i]==1)
                continue;
        if(proc[i].BT==0)
        {   
            v[i]=1;
            j=j+1;
            proc[i].status=2;
            int c=0;
            for(int l=0;i<number;i++)
            {  
               if(l==i)
               {
                continue;
               proc[l].priority=1+(proc[l].WT/proc[l].BT);
               if(c==0)
               {
                prior=l;
                c++;
                }
               if(proc[l].priority>proc[prior].priority)
                prior=l;
                }
            }
        }
        }
    }
    
     min_at=min_at+1;
     if(min_at<CT)
        goto X;

    for(int i=0;i<number;i++)
        proc[i].TT=proc[i].BT1+proc[i].WT;

    for(int i=0;i<number;i++)
        TTT=TTT+proc[i].TT;

    for(int i=0;i<number;i++)
        TWT=TWT+proc[i].WT;
     
    ATT=TTT/number;
    AWT=TWT/number;


    printf("\n\nProcess                                  Waiting Time                                 Turnaround Time\n");
    for(int i=0;i<number;i++)
    {
      printf("  %d                                      %.2f                                            %.2f\n",proc[i].pid,proc[i].WT,proc[i].TT);
    }
      printf("                                    Average Waiting Time                         Average Turnaround Time\n");
      printf("                                          %.2f                                            %.2f\n",AWT,ATT);

}











