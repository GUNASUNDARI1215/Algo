// C program to display the transpose Matrix

#include<stdio.h>

int main()
{
	int rows,columns,i,j;
	
	printf("Enter the number of rows: ");
	scanf("%d",&rows);
	
	printf("Enter the number of columns: ");
	scanf("%d",&columns);
	
	int arr[rows][columns];
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Element[%d][%d]= ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	
	printf("Entered matrix: \n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("Transpose Matrix: \n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d ",arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}
