/*
THREE NUMBER SUM: 

Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. 
The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. 
The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers 
they hold.

If no three numbers sum up to the target sum, the function should return an empty array.

Sample Input

	array [12, 3, 1, 2, 6, 5, -8, 6]

	targetSum=0
	
Sample Output
	
	[-8,2,6],[-8,3,5],[-6,1,5]

*/

#include<stdio.h>

int partition(int *A,int start,int end)
{
	int pivot=A[end];
	int partition_index=start;
	int i,t,temp;
	
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			temp=A[i];
			A[i]=A[partition_index];
			A[partition_index]=temp;
			partition_index++;
		}
	}
	
	t=A[partition_index];
	A[partition_index]=A[end];
	A[end]=t;
	
	return partition_index;
}

int Quicksort(int *A,int start,int end)
{
	if(start<end)
	{
		int partition_index=partition(A,start,end);
		Quicksort(A,start,partition_index-1);
		Quicksort(A,partition_index+1,end);
	}
}

int triplet(int Arr[],int size,int target_sum)
{

	int i,triplet_arr[3]={0};
	
	for(i=0;i<size-2;i++)
	{
		int left_ptr=i+1;
		int right_ptr=size-1;
	
		while(left_ptr<right_ptr)
		{
			int sum=Arr[left_ptr]+Arr[right_ptr]+Arr[i];
			if(sum==target_sum)
			{
				triplet_arr[0]=Arr[left_ptr];
				triplet_arr[1]=Arr[right_ptr];
				triplet_arr[2]=Arr[i];
				left_ptr++;
				right_ptr--;
			}
	
			else if(sum<target_sum)
				left_ptr++;
		
			else if(sum>target_sum)
				right_ptr--;
		}
	}

printf("The Three number Sum is obtained by: ");
for(i=0;i<3;i++)
{
	printf("%d ",triplet_arr[i]);	
}

}

int main()
{
	int size,i;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	
	int arr[size];
	printf("Enter the elements of array: \n");
	for(i=0;i<size;i++)
	{
		printf("Element[%d] - ",i);
		scanf("%d",&arr[i]);
	}
	
	int targetSum=0;
	printf("Enter the target Sum : ");
	scanf("%d",&targetSum);
	
	//sort the Array
	Quicksort(arr,0,size-1);
	
	//calculate the three number sum	
	triplet(arr,size,targetSum);
	
	return 0;
}


