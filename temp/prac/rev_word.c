#include </home/mirafra/Desktop/temp/header.h>

/*

int main()
{
	char p[] = "I am a good boy";
	char *rev = &p[strlen(p)];
	
	char out[100];
	bzero(out,100);

	int i = 0;
	int size = strlen(p) ;
	printf("%d\n",size);

	printf("Before :  %s\n\n\n",p);
	


	while(i <= size)
	{
		while(*rev != ' ')
		{
			rev--;
			i++;

		}
		printf("%d ",i);

		strcat(out,rev);
		*rev = '\0';
		rev--;
		i++;
	}

	out[size] = p[0];
	out[size + 1] = '\0';


	printf("\n\n\n\nAfter :  %s\n",out);

	return 0;
}

*/

//second method
//

void rev_wrd(char *wrd)
{
	char temp;

	for(int i = 0 ; i < (strlen(wrd)/2) ; i++)
	{
		temp = wrd[i];
		wrd[i] = wrd[strlen(wrd) - i - 1];
		wrd[strlen(wrd) - i - 1] = temp;

	}

}

void act_rev(char *str)
{
	rev_wrd(str);
	char temp[30];
	bzero(temp,30);
	char output[30];
	bzero(output,30);
	int size = strlen(str);
	while(size>0){
		int i = 0;
		size--;
		bzero(temp,30);

		if(*str == ' ')
		{
			temp[i++] = *str;
			str++;
			rev_wrd(str);

		}
		temp[i] = '\0';
		rev_wrd(temp);
		strcat(output,temp);
		str++;
	}
	//
	printf("%s",output);

}


int main()
{
	char p[] = "Bhaskar is an";

	act_rev(p);
	//printf("%s",p);

	return 0;
}
