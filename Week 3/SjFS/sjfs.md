SHORTEST JOB REMAINING  ALGORITHM

The code above implements the Shortest Remaining Time First (SRTF) scheduling algorithm for a given set of processes.

The program starts by taking input from the user for the number of processes and their arrival time and burst time. It then stores this information in an array of struct named "process".

The program then initializes a current time variable "t" and a counter "completed" to keep track of the number of processes that have completed execution.

It then enters a while loop, which continues until all the processes have completed execution. In each iteration of the loop, the program looks for the process with the shortest remaining time among the processes that have already arrived and have not yet completed execution.

If there is no such process, the program increments the current time variable and continues with the next iteration. Otherwise, the program executes the process with the shortest remaining time for one unit of time.

If a process completes execution, the program updates its turnaround time and waiting time, and increments the counter for completed processes.

Finally, the program prints out the process details, including their arrival time, burst time, turnaround time, and waiting time, as well as the average waiting time and average turnaround time for all the processes.



