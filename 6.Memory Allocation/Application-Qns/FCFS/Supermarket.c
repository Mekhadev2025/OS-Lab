
// // A supermarket uses a computer system to manage its inventory. The inventory database is stored on a disk, 
// and the system retrieves data as items are scanned at the checkout counter. The disk stores data in sequential blocks,
//  and the time it takes to access a block depends on the physical location of the disk's read/write head.

// // Suppose a supermarket has the following inventory stored on the disk:

// // Block 0 to Block 9: Canned Goods
// // Block 10 to Block 19: Dairy Products
// // Block 20 to Block 29: Fresh Produce
// // Block 30 to Block 39: Snacks
// // Block 40 to Block 49: Toiletries
// // The disk's read/write head is currently at Block 5. The supermarket scans items in the order 
// they are requested by customers. Assume that the disk head takes 1 time unit to move between adjacent blocks and no time to read the actual data.

// // Customer Requests (in order):

// // Canned Goods
// // Fresh Produce
// // Snacks
// // Dairy Products
// // Toiletries

// // Calculate the total time taken to fulfill these customer requests using the First-Come-First-Served (FCFS) disk scheduling algorithm. 

// Show each step of the process.

// // Remember that the FCFS algorithm serves requests in the order they are received.

// // Note: This question involves simulating the disk head movement and calculating the time taken for each movement and request completion. 
// You'll need to calculate the distance the disk head travels between blocks and add up the time units accordingly.


//Answer

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int count=0;
    int rq[]={0,20,30,10.40};
    int head=5;
    int n=5;
    int totalMov=0;
    int initial=head;
    for(int i=0;i<n;i++)
    {
        
        totalMov=totalMov+abs(rq[i]-initial);
        initial=rq[i];
    }
    printf("\nTotal Movement =%d",totalMov);
      return 0;

}