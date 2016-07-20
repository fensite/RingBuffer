#include <stdio.h>
#include<ctype.h>
#define NMAX 4

int iput=0;
int oget=0;
int n=0;
int buffer[NMAX];
int addring(int i)
{
	return (i+1)==NMAX?0:i+1;
}
void put(int w)
{
	if(n<NMAX)
	{
		buffer[iput] = w;
		iput=addring(iput);
		n++;
	}
	else
		printf("FULL!\n");
}
int get()
{
	int middle;
	if(n>0)
	{	
		middle=oget;
		oget=addring(oget);
		n--;
		printf("the num is %d\n",buffer[middle]);
		return buffer[middle];
	}
	else
		printf("EMPTY!\n");
}
int main()
{
	char signal[5];
	int w;
	while(signal[0] != 'e')
	{
	printf("Please chose one word from p|g|e:\n");
	scanf("%c",signal);
	getchar();
//	while(signal[0] != 'e')
	switch(signal[0]){
		case 'p':
			printf("Please putin a number:\n");
			scanf("%d",&w);
			getchar();
			put(w);
			break;
		case 'g':
			w=get();
			break;
		case 'e':
			printf("END!\n");
			break;
		default :
			printf("%c isnot  one of the three!\n",signal[0]);
		}
	}//	while(signal[0] != 'e')
			return 0;
}

