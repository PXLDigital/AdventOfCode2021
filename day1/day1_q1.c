#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 255

int linesN(FILE *fp);
void printBinary(int number);

int main() {
   FILE *fp;
   int inputN = 0;
   fp = fopen("day1_q1_input.txt", "r+");
   if(fp==NULL)
   {
	   perror ("Error opening file");
   }
   
   
   char data[linesN(fp)][BUFF];
   inputN=linesN(fp);

   for(int i=0; fgets(data[i], BUFF, fp)!=NULL;i++)
   {
	   //data[i][strlen(data[i])-1]='\0';
	   printf("read line\n");
   }
   for(int i=0; i<inputN; i++)
   {
	   printf("%s",data[i]);
   }
   
   for(int i=0; i<10;i++)
   {
	   printf("--------------------------------------------\n");
   }
   printf("Reading complete!\n");
   for(int i=0; i<10;i++)
   {
	   printf("--------------------------------------------\n");
   }
   
   int increase = 0;
   int decrease = 0;
   for(int i=1; i<(inputN);i++)
   {
	   int temp = atoi(data[i]);
	   int prev = atoi(data[i-1]);
	   printf("%d %d ",temp,prev);
	   if(temp > prev)
	   {
		   increase++;
		   printf("increase\n");
	   }
	   else{
		   decrease++;		   
		   printf("decrease\n");
	   }
	   
   }
   printf("increase %d\n",increase);
   printf("decrease %d\n",decrease);
   return 0;
}

int linesN(FILE *fp)
{
	int inputN = 0;
	char temp = 0;
	do
   {
	   temp = fgetc(fp);
	   if(temp == 10)//newline what about carriage return? ->no issue
	   {
		   ++inputN;
	   }
   }while(temp != EOF);
   rewind(fp);
   return inputN;
}

void printBinary(int number)
{
	int bitsN = sizeof(number)*8;
	unsigned int numberUN = (unsigned int) number;
	unsigned int mask = 1<<(bitsN-1);
	unsigned int result = 0;
	for(int i =0;i<bitsN;i++)
	{
		result=0;
		result = mask & numberUN;
		result = result>>(bitsN-1-i);
		printf("%d",result);
		mask = mask>>1;
	}
	printf("\n");
}
