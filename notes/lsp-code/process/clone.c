#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sched.h>

int myfn();

#define STACK_SIZE (1024)

int xyz = 100;

int main()
{
	int *st,k=9;
	static int m = 100;
	st = (int *)malloc(STACK_SIZE);
	st = st+STACK_SIZE; //Pointing to the top of the stack considering stacks growns down
	pid_t p1;
	p1 = clone(myfn,st,CLONE_VM | CLONE_THREAD | SIGCHLD,NULL);
	sleep(5);
	printf("Stack address: local = %p heap = %p  data = %p  %p : %d\n", &st, st, &m,&xyz, xyz);	
	if(p1<0)
			perror("error in fork:");
	printf("before child.....................ppid = %d    pid = %d\n",getppid(), getpid());
	if(p1==0)
			printf("i am in child...............");
	else
			printf("i am from parent.......................\n");
	sleep(2);
}
int myfn()
{
	int x = 10;
	static int y =20;
	xyz = 123;
	printf("i am from child fun %p  &x(local)=%p  %p : %d\n",__func__, &x,&xyz,xyz);
	printf("main =%p  &y(data) = %p....\n",main,&y);
	printf("In child.....................ppid = %d    pid = %d\n",getppid(), getpid());
}
