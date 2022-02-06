/* 
C Program : Filter the vowels in the input string and check whether the filtered string is a palindrome

Input1: miami
explanation: vowels:iai => palindrome

Input: welcome
explanation: vowles:eoe => palindrome
*/

#include<stdio.h>

int main()
{
	int size;
	printf("Enter the size of str1: ");
	scanf("%d",&size);
	
	char str1[size+1];
	char vowel[size];
	printf("Enter the str1: ");
	scanf("%s",str1);
	
	int i,j=0;
	
	for(i=0;str1[i]!='\0';i++)
	{
		if( str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' ||
		    str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U' )
		    {
		    	vowel[j]=str1[i];
		    	j++;	    	
			}
	}
	
	printf("Vowel string is: %s\n",vowel);
	
	//Check for palindrome
	int flag=0;
	int len=strlen(vowel);
	for(i=0;i<len;i++)
	{
		if(vowel[i]!=vowel[len-i-1])
		{
			flag=1;
		}	
		break;		
	}
		
	if(flag==0)
		printf("The vowels from given string forms a Palindrome");
	else
		printf("The vowels from given string doesn't form a Palindrome");
		
	return 0;
}
