/*
------------------TWO SUM------------------

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include<stdio.h>

int result[2]={0};

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
	
	int arr1[size],i;
	for(i=0;i<size;i++)
	{
		arr1[i]=Arr[i];
	}
	
	//Sort the array using Quicksort
	Quicksort(Arr,0,size-1);
	
	int left=0;
	int right=size-1;

	
    while(left!=right)
	{
		int target=Arr[left]+Arr[right];
		if(target==targetSum)	
		{
			result[0]=Arr[left];
			result[1]=Arr[right];
			printf("The target sum is obtained from ");
			for(i=0;i<2;i++)
			{
				printf("[%d]",result[i]);
			}
		
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

	printf("The target is not found");
	exit(0);
	
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
	
	int original_arr[size];
	for(i=0;i<size;i++)
	{
		original_arr[i]=arr[i];
	}	
	
	int targetSum=0;
	printf("Enter the target Sum : ");
	scanf("%d",&targetSum);
	
	twonumbersum(arr,size,targetSum);
	
	int index1,index2;	
	for(i=0;i<size;i++)
	{
		if(original_arr[i]==result[0])
		{
			index1=i;
			i++;
		}
			
		if(original_arr[i]==result[1])
			index2=i;
	}
	printf("\nThe target sum is obtained at the index: %d,%d",index1,index2);
		
	return 0;
}
