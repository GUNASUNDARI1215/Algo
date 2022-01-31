//*****USING HASH TABLE*****

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
#define MAX 100

int twonumbrr(int arr[],int targetSum,int size)
{
	int num,target;
	int h[MAX] = { 0 };

	for (num=0;num<size;num++)
	{
		target=targetSum-arr[num];
		if (h[target]==1)
		{
			printf("(%d,%d)",arr[num],target);
			return;
		}
		h[arr[num]]=1;
	}
	
	printf("(0,0)");
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
	
	printf("The targetSum is obtained by: ");
    twonumbrr(arr,targetSum,size);
	
	return 0;
}
