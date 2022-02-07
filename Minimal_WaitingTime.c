/*

Minimum Waiting Time

You're given a non-empty array of positive integers representing the amounts of time that specific queries take to execute. 
Only one query can be executed at a time, but the queries can be executed in any order.

A query's waiting time is defined as the amount of time that it must wait before its execution starts. 
In other words, if a query is executed second, then its waiting time is the duration of the first query; 
if a query is executed third, then its waiting time is the sum of the durations of the first two queries.

Write a function that returns the minimum amount of total waiting time for all of the queries. For example, 
if you're given the queries of durations [1, 4, 5]. then the total waiting time if the queries were executed in the order 
of [5, 1, 4] would be (0) (5) (5+1) = 11. The first query of duration 5 would be executed immediately, so its waiting time would be 0, 
the second query of duration 1 would have to wait 5 seconds (the duration of the first query) to be executed, 
and the last query would have to wait the duration of the first two queries before being executed.

Note: you're allowed to mutate the input array.

Sample Input

queries [3, 2, 1, 2, 6]

output:17

*/

#include<stdio.h>

int partition(int *A, int start, int end)
{
	int pivot=A[end];
	int partitionIndex=start;
	int i,temp,t;
	
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			temp=A[i];
			A[i]=A[partitionIndex];
			A[partitionIndex]=temp;
			partitionIndex++;			
		}
	}
		t=A[partitionIndex];
		A[partitionIndex]=A[end];
		A[end]=t;
		
		return partitionIndex;
}

void Quicksort(int *A,int start, int end)
{
	if(start<end)
	{
		int partitionIndex=partition(A,start,end);
		Quicksort(A,start,partitionIndex-1);
		Quicksort(A,partitionIndex+1,end);
	}
}

int waitingtime(int queries[],int size)
{
	int i,totaltime=0;
	int queriesleft;
	for(i=0;i<size;i++)
	{	
		queriesleft=size-(i+1);
		totaltime+=queriesleft*(queries[i]);
	}
	printf("\nThe minimal waiting time=%d\n",totaltime);
}

int main()
{
	int size,i;
	printf("Enter the total number of queries : ");
	scanf("%d",&size);
	
	int arr[size];
	printf("Enter the queries: \n");
	for(i=0;i<size;i++)
	{
		printf("Element[%d] - ",i);
		scanf("%d",&arr[i]);
	}
		
	//Sort the array using Quicksort
	Quicksort(arr,0,size-1);
	printf("The queries are executed in order of : ");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
		
	waitingtime(arr,size);
		
	return 0;
}
	