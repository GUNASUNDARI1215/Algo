// C program to print the pascals triangle

#include<stdio.h>

int main()
{
	int rows,i,j,c,k,place;
	
	printf("Enter the rows: ");
	scanf("%d",&rows);
	
	place=rows;
	
	printf("Pascals triangle: \n");
	for(i=0;i<rows;i++)
	{
		for(k=place;k>=0;k--)
			printf(" ");
		place--;
		
		for(j=0;j<=i;j++)
		{
			if(i==0 || j==0)
				c=1;
			else
				c=(c*(i-j+1))/j;
			printf("%d ",c);
		}
			
		printf("\n");

	}

	return 0;

}
