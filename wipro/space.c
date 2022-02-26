/*
 C program to add spaces after every X char
 
 An e-commerce company has a product list in its database. Each product key in the list is space separated, but due to a bug all the product key were combined,
 converting the list in to a string. The manager wishes to reproduce the product list by adding whitespaces after every X character in the string formed due to 
 the bug.
 so as a output print a space-separated string containing the product keys. The string should contain white_spacesnafter each charCount character.
 
 
 sample 1:
 
 Input: 
 	string:abcdefg
 	charCount:2
 	
 Output: ab cd ef g
 
 sample 2:
 
 Input:
 	string:dhgjdxgjk
 	charCount: 3
 	
 output: dhg jdx gjk 
 
 */
 

#include<stdio.h>

int main()
{
	int size,i;
	printf("Enter the size of the string: ");
	scanf("%d",&size);
	
	char str[size];
	printf("Enter the string: ");
	scanf("%s",str);
	
	int charCount;
	printf("Enter the count : ");
	scanf("%d",&charCount);
	
	for(i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
		if((i+1)%charCount == 0) 
			printf(" ");
	}
	
	return 0;
}
