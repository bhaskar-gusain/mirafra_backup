#define _GNU_SOURCE
#include <err.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <unistd.h>

int myfn(void*);


int main()
{
	int *st,k=9;
	st = (int *)malloc(2000)+2000;
	pid_t p1;
	p1 = clone(myfn,st,SIGCHLD,&k);	
	if(p1<0)
		perror("error in fork:");
	printf("before child.....................\n");
	if(p1==0)
		printf("i am in child...............");
	else
		printf("i am from parent.......................\n");
}

int myfn(void *arg)
{
	int kk = *(int*) arg;
	printf("i am from child fun  %d.....................\n",kk);
return 0;
}
