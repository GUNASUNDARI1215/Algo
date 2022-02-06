/*
Write a function that takes in an non-empty array of integers that are stored in ascending order and returns a new array of the same length
with the squares of the original integers also stored in ascending order.

Sample Input:
array=[1,2,3,4,6,8,9];

Sample Output:
[1,4,9,25,36,64,81];

*/

#include<stdio.h>

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

int squaredArray(int arr[],int size)
{
	int i=0;
	int squaredArray[size];
	for(i=0;i<size;i++)
	{
		squaredArray[i]=arr[i]*arr[i];
	}
	printf("The Sorted Squared Array is : ");
	for(i=0;i<size;i++)
	{
		printf("%d ",squaredArray[i]);
	}
}

int main()
{
	int size,i;
	printf("Enter the size of an array: ");
	scanf("%d",&size);
	
	int arr[size];
	printf("Enter the elements of the array: \n");
	for(i=0;i<size;i++)
	{
		printf("Element[%d] - ",i);
		scanf("%d",&arr[i]);
	}
	
	Quicksort(arr,0,size-1);
	squaredArray(arr,size);
	

	return 0;
}
