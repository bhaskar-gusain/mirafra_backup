#include "header.h"

int main()
{
	
	FILE *fp;
	char y[] = "Hi How are you\nI'm fine and happy\n\n\nYO ";

	fp = fopen("int.txt","w");

	if(fp == NULL)
	{
		perror("File opening");
	}
	
	int ret = fwrite(y,sizeof(y),1, fp);	
		
	
	int x = fclose(fp);

	if(x != 0)
	{
		perror("File closing");
	}
	
	return 0;
}
