#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"

int main(void)
{
	int x;
	char *answer;
	if((answer=malloc(21*(sizeof (char))))==NULL)
	{
		printf("Not enough space, shutting down programm.\n");
	}
	printf("Do you want to read a joke or to tell me one?\n(answer with 'read' or 'tell')\n");
	fgets(answer,21,stdin);
	if(0==strcmp(answer,"read\n"))
	{
		printf("Let me choose one, hit Enter when ready to laugh :P\n");
		getchar();
		if(read())
		{
			printf("I found no jokes!! Pls update me :P\n");
		}
		getchar();
	}
	else
	{
		printf("Okie dokie, go on then :D\n");
		if(tell()==1)
		{
			printf("No space available buddy...\n");
		}
		printf("Hahahahaha, nice one! :D\n");
		getchar();
	}
	free(answer);
	return 0;	
}
