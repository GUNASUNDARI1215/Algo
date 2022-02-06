/*
Non-Constructible Change 

Given an array of positive integers representing the values of coins in your possession, write a function that returns the minimum amount of change
 (the minimum sum of money) that you cannot create. The given coins can have any positive integer value and aren't necessarily unique 0e, you can have
  multiple coins of the same value) For example, if you're given coins [1, 2, 5), the minimum amount of change that you can't create is (4). 
  If you're given no coins, the minimum amount of change that you can't create is 1

Sample input

[5, 7, 1, 1, 2, 3, 22]

Sample Output:
20
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

int constructiblechange(int coins[],int count)
{
	int change=0,i;
	for(i=0;i<count;i++)
	{
		if(coins[i]>change+1)
		{
			return change+1;
		}
		change+=coins[i];
	}
	return change+1;
}

int main()
{
	int count,i;
	printf("Enter the total count of coins: ");
	scanf("%d",&count);
	
	int coins[count];
	printf("Enter the coins: \n");
	for(i=0;i<count;i++)
	{
		printf("Coin[%d]- ",i);
		scanf("%d",&coins[i]);
	}
	
	Quicksort(coins,0,count-1);
		
	int output=constructiblechange(coins,count);
	printf("The minimum amount of change that can't be created is : %d",output);
		
    return 0;	
}

