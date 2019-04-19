/*Assume that we have a demand-paged memory. The page table is held in registers.
It takes 8 milliseconds to service a page fault if an empty frame is available
or if the replaced page is not modified and 20 milliseconds if the replaced
page is modified.Memory-access time is 100 nanoseconds. Assume that the page to
be replaced is modified 70 percent of the time.What is the maximum acceptable page-fault
rate for an effective access time of no more than 200 nanoseconds?

For this problem we will use this formula to calculate Page fault:

Avg time = (Page Fault)*( Modified( Time ) +  (1- Modified) (Time)) + (1- Page Fault)*Memory time

After modification,the formula for page fault will be:

page fault = (Avg time - Memory access time)/(( Modified( Time )+(1- Modified) (Time)) - Memory access time)


*/

#include<stdio.h>
#include<stdlib.h>

int main()
{

	double page_fault;//Page fault in percentage.
	double avg_time;// Average time in nanoseconds.
	double memory_acc_time; // Memory time in nanoseconds.
	double modified_per;//Modification in percentage.
	double time_n; // This variable represents time when replaced page is not modified.
	double time_m; // This variable represents time when replaced page is  modified.

	printf("                  ----Demand Paged Memory Problem----  \n\n");
    printf("For this problem take the values given below or you can take your own values! \n\n");
    printf("Average time =  200 | Memory Access Time = 100 | Modification Percentage = 70%%|");
    printf(" Time_n = 8 | Time_m = 20\n\n");
	

    printf("Average time :");
    scanf("%lf",&avg_time);

    printf("\nMemory Access time :");
    scanf("%lf",&memory_acc_time);

    printf("\nModification percentage :");
    scanf("%lf",&modified_per);
    modified_per /= 100;

    printf("\nTime when not modified(Time_n):");
    scanf("%lf",&time_n);
    time_n *= 1000000;//converting in nanoseconds.

    printf("\nTime when modified(Time_m):");
    scanf("%lf",&time_m);
    time_m *= 1000000;//converting in nanoseconds.

    page_fault = (avg_time - memory_acc_time)/(( modified_per*(time_m)+(1 - modified_per)*(time_n)) - memory_acc_time);

    printf("\nThe maximum acceptable page-fault rate for an effective access time : %lf%%\n\n",page_fault);
}
