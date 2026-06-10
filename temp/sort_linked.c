#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"


struct node
{
	void* data;
	struct node *next;
}*head;

void ins(void* data,int pos)
{
	struct node *temp, *mem;
	mem = (struct node*)malloc(sizeof(struct node));
	mem->data = (int*)malloc(sizeof(int));
	*(int*)mem->data = *(int*) data;
	mem->next = NULL;
	temp = head;

	if(head == NULL)  //beginning
	{
		head = mem;
		return;
	}

	for(int i = 0 ; i < pos-1 ; i++)
	{
		temp = temp->next;
	}
	mem->next = temp->next;
	temp->next = mem;
	return;

}

void print()
{
	struct node *temp = head;

	if(head == NULL)
	{
		printf("Empty list");
		return;
	}

	while(temp != NULL)
	{
		printf("add - %p , data - %d , next - %p\n",temp,*(int*)temp->data,temp->next);
		temp=temp->next;
	}
}


int main()
{
	head = NULL;
	
	int x = 10;
	char *str = "Bhaskar";
	void* p =&x;	
	ins(p,0,);
	
	void* p = str;
	ins(p,1);

	//ins(30,2);
	//ins(40,1);
	//ins(50,4);

	print();

	free(head);
	return 0;

}

