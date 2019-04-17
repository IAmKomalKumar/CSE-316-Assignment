/* Design a scheduler with multilevel queue having two queues which will schedule the processes on 
the basis of  preemptive shortest remaining processing time first algorithm (SROT) followed by
a scheduling in which each process will get 2 units of time to execute. Also note that queue 1 
has higher priority than queue 2.  Consider the following set of processes (for reference)with
their arrival times and the CPU burst times in milliseconds.
-------------------------------------
Process  Arrival-Time   Burst-Time
-------------------------------------
P1             0      	       5
P2             1               3
P3             2               3
P4             4               1
-------------------------------------

*/


#include<stdio.h>
#include<stdlib.h>
typedef struct
{

    int arrival_time,burst_time,queue;
    int process_id;
}process;

int main()
{
    int size;//Number of processes
    int count = 0;
    int time,smallest,waiting_time[50],turnaround_time[50],completion[50],temp_burst[50];
    double average_waiting,average_turnaround;
    printf("\nEnter the number of processes:");
    scanf("%d",&size);
    process no[size];
    for(int i = 0; i < size; i++)
	{
		printf("\nProcess ID:\t");
		scanf("%d", &no[i].process_id);
		printf("Arrival Time:\t");
		scanf("%d", &no[i].arrival_time);
		printf("Burst Time:\t");
		scanf("%d", &no[i].burst_time);
		printf("Queue1/Queue2(1/2):\t");
		scanf("%d", &no[i].queue);
	}
    for(int i=0;i<size;i++)
    {
        temp_burst[i] = no[i].burst_time;//storing the burst time in a array for  further use.
    }
    no[size+1].burst_time = 999;//  assign a max burst for comparison
    for(time=0;count!=size;time++)
    {
         smallest = size+1;
         for(int i=0;i<size;i++)
         {
            if(no[i].arrival_time<=time && no[i].burst_time<no[smallest].burst_time&& no[i].burst_time>0 )
            smallest=i;
         }
         no[smallest].burst_time--;
         if(no[smallest].burst_time == 0)
         {
            count++;
            completion[smallest] = time+1;
            turnaround_time[smallest] = completion[smallest] - no[smallest].arrival_time;
            waiting_time[smallest] = turnaround_time[smallest] - temp_burst[smallest];
         }
    }
    printf("\n\nProcess Id\tArrival Time\t Burst Time\t Waiting Time\tTurnaround Time");
    for(int i=0;i<size;i++)
    {
        printf("\n   %d    \t\t%d\t\t%d  \t\t%d\t\t%d",no[i].process_id,no[i].arrival_time,temp_burst[i],waiting_time[i],turnaround_time[i]);
        average_waiting += waiting_time[i];
        average_turnaround += turnaround_time[i];
    }
    printf("\n\nAverage waiting time = %lf\n",average_waiting/size);
    printf("Average Turnaround time = %lf",average_turnaround/size);
    getch();

}
