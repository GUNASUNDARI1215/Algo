/*
C Program to the folder for storing the packets

The data network of MNC 'CompSoft' transmits a list consists  of the packetId of the packets to be transmitted.
The packetId is a numeric value consisting of digits from 0-9.
The sum of all even digits present in the packetId is the folder number in which the data must be stored upon transmission to the next server.
The company wishes to find out the folder number of all the N data packets.

Write an algorithm to find the folder number from the packetId of all the N data packets.

Sample Input 1:

	numPackets=3
	packetId= 11 22 24
	
	ouput:	0 4 6
	
Sample Input 2:

	numPackets=5
	packetId= 43 236 11 482 10
	
	ouput: 4 8 2 14 0
	
*/

#include<stdio.h>

int main()
{
	int numPackets,i;
	printf("Enter the number of packets: ");
	scanf("%d",&numPackets);
	
	int packetId[numPackets];
	printf("Enter the packetId: \n");
	for(i=0;i<numPackets;i++)
	{
		printf("packetId[%d]: ",i+1);
		scanf("%d",&packetId[i]);
	}
	
	int sum=0,remainder,Id;
	printf("The packetId's are stored in the folder: \n");
	for(i=0;i<numPackets;i++)
	{
		Id=packetId[i];
		sum=0;
		
		while(Id>0)
		{
			remainder=Id%10;
			if(remainder%2==0)
			{
				sum+=remainder;
			}
			Id=Id/10;
		}
		printf("%d ",sum);
	}
	
	return 0;
	
}
