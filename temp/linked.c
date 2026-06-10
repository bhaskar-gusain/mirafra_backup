#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"


struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;

void ins(int data,int pos)
{
	struct node *temp, *mem;
	mem = (struct node*)malloc(sizeof(struct node));
	mem->data = data;
	mem->next = NULL;
	mem->prev = NULL;
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
	mem->prev = temp;
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
		printf("add - %p , data - %d , prev - %p ,next - %p\n",temp,temp->data,temp->prev,temp->next);
		temp=temp->next;
	}
}

void del(int pos)
{
	struct node *temp;
	temp = head;

	if(head == NULL)
	{
		printf("Empty list\n");
		return;
	}

	if(pos == 0)  //head
	{
		head = head -> next;
		free(temp);
		return;
	}
	
	for(int i = 0 ; i < pos-1 ; i++)
	{
		temp = temp->next;
	
	}

	temp->next = temp->next->next;

	return;
}

void rev()
{
	struct node *p1,*p2,*p3;

	p1=head;
	p2=p1->next;
	p3=p2->next;

	p2->next = p1;
	p2->prev = p3;
	p1->prev = p2;
	p1->next = NULL;
	

	while(p3 != NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->next;

		p2->next = p1;
		p2->prev = p3;
	}

	head = p2;
}


int main()
{
	head = NULL;
	

	
	ins(10,0);
	ins(20,1);
	ins(30,2);
	ins(40,1);
	ins(50,4);
	print();

	printf("\n-------------After reverse-------------\n\n");
rev();

	print();


	free(head);
	return 0;

}

