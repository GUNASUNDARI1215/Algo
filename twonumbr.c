/*
write a function that takes in a non-empty array of distinct  integers and an integer representing a target sum.
If any two numbers in the input array sum up to the target sum, the function should return them in an array,
in any order. If no two numbers sum up to the target sum, the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array, you can't add a single 
integer to itself in order to obtains the target sum.

You can assume that there will be at most one pair of numbers summing up to the target sum.

Sample Input:
	array=[3,5,-4,8,11,1,-1,6]
	targetSum=10
Sample Output:
	[-1,11] //The numbers could be in reverse order
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

int twonumbersum(int Arr[],int size,int targetSum)
{
	int left=0,i;
	int right=size-1;
	int result[2]={0};
	
    while(left!=right)
	{
		int target=Arr[left]+Arr[right];
		if(target==targetSum)	
		{
			result[0]=Arr[left];
			result[1]=Arr[right];
			for(i=0;i<2;i++)
			{
				printf("[%d]",result[i]);
			}
			printf("\nThe target sum is obtained at the index: %d,%d",left,right);
			return ;
		}
			
		else if(target<targetSum)
		{
	 		left++;
		}
			
		else
		{
			right--;
		}
	}
	
	for(i=0;i<2;i++)
	{
		printf("[%d]",result[i]);
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
	
	int targetSum=0;
	printf("Enter the target Sum : ");
	scanf("%d",&targetSum);
	
	//Sort the array using Quicksort
	Quicksort(arr,0,size-1);
	
	printf("The targetSum is obtained by: ");
	twonumbersum(arr,size,targetSum);
 
	
	return 0;
}
