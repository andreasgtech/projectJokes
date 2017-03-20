#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"

int main(void)
{
	int x;
	char *answer;
	if ((answer=malloc(21*(sizeof (char))))==NULL)
	{
		fprintf(stderr,"Not enough space, shutting down programm.\n");
		return -1;
	}
	printf("Do you want to read a joke or to tell me one?\n(answer with 'read' or 'tell', type exit for the obvious reason)\n");
	fgets(answer,6,stdin);
	while (0!=strcmp(answer,"exit\n"))
	{
		if (0==strcmp(answer,"read\n"))
		{
			fprintf(stderr,"Let me choose one, hit Enter when ready to laugh :P\n");
			getchar();
			if(read())
			{
				fprintf(stderr,"I found no jokes!! Pls update me :P\n");
			}
		}
		else if (0==strcmp(answer,"tell\n"))
		{
			fprintf(stderr,"Okie dokie, go on then :D\n");
			if(tell()==1)
			{
				fprintf(stderr,"No space available buddy...\n");
			}
			fprintf(stderr,"Hahahahaha, nice one! :D\n");
		}
		else
		{
			fprintf(stderr,"Please select a valid choice:\n");
		}
		fprintf(stderr,"(answer with 'read' or 'tell', type exit for the obvious reason)\n");
		fgets(answer,6,stdin);
	}
	free(answer);
	return 0;	
}
