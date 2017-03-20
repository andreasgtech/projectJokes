#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int tell(void)
{
	FILE *data,*counter;
	char *joke;
	unsigned int a;
	counter=fopen("counter.txt","r");
	fscanf(counter,"%d",&a);
	fclose(counter);
	if((joke=malloc(101*sizeof(char)))==NULL)
	{
		return 1;
	}
	fgets(joke,101,stdin);
	if(0==strcmp(joke,"Knock knock?\n"))
	{
		data=fopen("data.txt","a");
		fprintf(data,"-Knock knock?\n-Who's there?\n");
		printf("Who's there?\n");
		fgets(joke,101,stdin);
		joke[strlen(joke)-1]='\0';
		fprintf(data,"-%s.\n-%s who?\n",joke,joke);
		printf("%s who?\n",joke);
		fgets(joke,101,stdin);
		fprintf(data,"-%s#\n",joke);
		fclose(data);
	}
	else
	{
		data=fopen("data.txt","a");
		fprintf(data,"%s#\n",joke);
		fclose(data);
	}
	a++;
	free(joke);
	counter=fopen("counter.txt","w");
	fprintf(counter,"%d",a);
	fclose(counter);
	return 0;
}

int read()
{
	FILE *data,*counter;
	unsigned int y,a;
	unsigned char b;
	y=time(NULL);
	srand(y);
	int i=0,value=rand();
	counter=fopen("counter.txt","r");
	data=fopen("data.txt","r");
	fscanf(counter,"%d",&a);
	if(!a)
	{
		return 1;
	}
	while(i!=(value%a+1))
	{
		b=fgetc(data);
		if(b=='#')
		{
			i++;
		}
	}
	while((b=fgetc(data))!='#')
	{
		printf("%c",b);
	}
	fclose(data);
	fclose(counter);
	return 0;
}
