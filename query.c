/*
C Program to find whether the replaced string is palindrome or not

sample input:
	
	string:geeks
	queries:2
	
	querie[1]: Change the indices: 3 0
			   Replaced by the character:'e'
			
	replaced string:eeees
			
	output: Not a palindrome
	
	querie[2]: Change the indices: 0 2
			   Replaced by the character:'s'
			   
	replaced string:seses
			
	output: palindrome
	
*/			

#include<stdio.h>

int checkpalindrome(char *str,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(str[i]!=str[size-1-i])
			return 0;
	}
	return 1;
}

void query(char *str,int size,int queries)
{
	int replacing_index1,replacing_index2,i;
	char replacing_char[1];
	for(i=0;i<queries;i++)
	{
		printf("Query[%d]: \n",i);
		
		printf("Change the indices: ");
		scanf("%d %d",&replacing_index1,&replacing_index2);
		
		printf("Replaced by the character: ");
		scanf("%s",replacing_char);
	
		//replacing characters:
		str[replacing_index1]=*replacing_char;
		str[replacing_index2]=*replacing_char;

		printf("The replaced string: %s\n",str);
	
		if(checkpalindrome(str,size))
			printf("The replaced string is palindrome\n");
		else
			printf("The replaced string is not a palindrome\n");
	}
}

int main()
{
	int size;
	printf("Enter the size of the string : ");
	scanf("%d",&size);
	
	char str[size];
	printf("Enter the string: ");
	scanf("%s",str);
	
	int queries;
	printf("enter the number of queries: ");
	scanf("%d",&queries);
	
	query(str,size,queries);
	
	return 0;
}
