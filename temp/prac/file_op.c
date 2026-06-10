//Reading files from directory recursively and searching a particular string in it


#include </home/mirafra/Desktop/temp/header.h>



int main()
{
	FILE *fd;
	char buffer[1000];
	bzero(buffer,1000);
	int count = 0;
	char *loc;
	long val = 0;

	fd = fopen("test.txt","r+");
	if (!fd) {
		perror("Opening");     
		exit(EXIT_FAILURE);
	}

	int ret = fread(buffer , sizeof(*buffer) , sizeof(buffer) , fd);
	if (ret == -1 ) {
		perror("Reading");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	while(1){

		loc = strstr(buffer,"hello");
		if(loc == NULL)
			break;
		val += (loc - buffer) + 6 ;

		count++;
		//printf("Before lseek -----------------------------------\n");


		//printf("%s",buffer);
		ret = fseek(fd , val , SEEK_SET);
		//printf("AFter lseek -----------------------------------\n");
		
		memset(buffer, 0, sizeof(buffer)); // Sets all bytes in the array to 0
		
		ret = fread(buffer , sizeof(*buffer) , sizeof(buffer) , fd);
		if (ret == -1 ) {
			perror("Reading");
			exit(EXIT_FAILURE);
		}

		//printf("%s",buffer);

	}

	printf("%d",count);

	fclose(fd);
	return 0;
}
