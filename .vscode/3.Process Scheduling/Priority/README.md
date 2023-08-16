<h1><b>PRIORITY SCHEDULING ALGORITHM </b></h1>
The given code is an implementation of the Priority Scheduling algorithm in C programming language.
The algorithm schedules processes based on their priority, with the highest priority process being executed first.

A macro named 'MAX' is defined with a value of 100. This macro is used to define the maximum number of processes that can be handled by the program.
A structure named 'Process' is defined with the following fields:
<ul>
  <li>'pid' to store the process ID</li>
<li>'arrival_time' to store the time at which the process arrives</li>
<li>'burst_time' to store the time required by the process to complete its execution</li>
<li>'priority' to store the priority of the process</li>
<li>'remaining_time' to store the time remaining for the process to complete its execution</li>
<li>'waiting_time' to store the time the process has to wait before it gets executed</li>
<li>'turnaround_time' to store the total time the process takes to complete its execution</li>
  </ul>
In the 'main' function:

--> 'n' variable is used to store the number of processes
--> 'i', 'j' and 't' variables are used as loop counters and 'completed' variable is used to keep track of the number of processes that have been completed.
'current_process' variable is used to store the process ID of the process that is currently being executed. Its initial value is set to -1.

An array of structures 'p' of size 'MAX' is defined to store the details of all the processes.

The user is asked to input the arrival time, burst time and priority of each process. These details are stored in the corresponding fields of the 'p' array. The 'remaining_time' field is also initialized with the 'burst_time' of each process, and the 'pid' field is initialized with the process ID.
A loop is started to execute the processes until all of them are completed.

Inside the loop, the algorithm finds the process with the highest priority that has arrived till that moment. If no process has arrived, it increments the time counter 't' and continues with the loop. If there is such a process, its ID is stored in the 'current_process' variable.

If a process has been selected for execution, it is executed for 1 unit of time by decrementing its 'remaining_time' field. If the 'remaining_time' of the process becomes 0, the process is marked as completed and the waiting and turnaround times are calculated.

The 'completed' counter is incremented, and the 'current_process' variable is set to -1, indicating that there is no process currently being executed.

After the loop finishes executing, the waiting and turnaround times for each process are printed along with the average waiting and turnaround times.

The implementation assumes that the processes are entered in the order of their arrival times. It may not be an optimal implementation as it does not take into account any preemption or context-switching.
