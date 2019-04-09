# CSE-316 Assignment
Solution of simulation based assignment for the course code 316(Operating Systems) .
# About Me
Name - Deepak Patel

Registration No - 11712706

Section - K17SM

Roll No - B46

Group - B

# Problem - 1

Design a scheduler with multilevel queue having two queues which will schedule the processes on the basis of  pre-emptive shortest remaining processing time first algorithm (SROT) followed by a scheduling in which each process will get 2 units of time to execute. Also note that queue 1 has higher priority than queue 2.  Consider the following set of processes (for reference)with their arrival times and the CPU burst times in milliseconds.


Process |  Arrival-Time |   Burst-Time
--------|---------------|--------------
P1      |       0      	|       5
P2      |       1       |      	3
P3      |       2       |       3
P4      |       4       |       1

Calculate the average turnaround time and average waiting time for each process. The input for number of processes  and their arrival time, burst time should be given by the user.


# Problem - 2

Consider a scenario of demand paged memory. Page table is held in registers. It takes 8 milliseconds to service a page fault if an empty page is available or the replaced page is not modified and 20 milliseconds if the replaced page is modified. Memory access time is 100 nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. Generate a solution to find maximum acceptable page-fault rate for access time that is not more than 200 nanoseconds.

# Solution

To solve this problem we have a formula which directly calculates the percentage of page fault.

Avg time = (Page Fault)*( Modified( Time ) + (1- Modified) (Time)) + (1- Page Fault)*Memory time

After modification,the formula for page fault will be:

page fault = (Avg time - Memory access time) / (( Modified( Time )+(1- Modified) (Time)) - Memory access time)

To comiple the file you can use the command:
```bash
gcc problem 2.c -o problem 2.out
```

##### ScreenShot

![imgur](https://imgur.com/XD4fkm8)




