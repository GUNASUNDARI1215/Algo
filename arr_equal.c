// C program to check whether two arrays are equal or not

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


int check_equal(int arr1[],int arr2[],int size1,int size2)
{
	int i;
	
	if(size1!=size2)
	{
		printf("Arrays are not equal");
		return ;
	}
	
	//sort the arrays
	Quicksort(arr1,0,size1-1);
	Quicksort(arr2,0,size2-1);

	for(i=0;i<size1;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			printf("Arrays are not equal");
			return;
		}
	}
	
	printf("Arrays are equal");
}

int main()
{
	int arr1_size,arr2_size,i;
	printf("Enter the size of arr1: ");
	scanf("%d",&arr1_size);
	
	int arr1[arr1_size];
	printf("Enter the elements of the arr1: \n");
	for(i=0;i<arr1_size;i++)
	{
		printf("Element[%d]- ",i);
		scanf("%d",&arr1[i]);
	}
	
	printf("Enter the size of arr2: ");
	scanf("%d",&arr2_size);
	
	int arr2[arr1_size];
	printf("Enter the elements of the arr1: \n");
	for(i=0;i<arr2_size;i++)
	{
		printf("Element[%d]- ",i);
		scanf("%d",&arr2[i]);
	}
	
	//check arrays are equal or not
	check_equal(arr1,arr2,arr1_size,arr2_size);
	
	return 0;
}
