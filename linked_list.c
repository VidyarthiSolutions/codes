#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	char    data;
	struct  node *next;
}NODE;

NODE *start = NULL;

void display()
{
	NODE *temp = start;

	if(temp == NULL)
		printf("LINKED LIST is empty!!\n");
	else
	{
		while(temp != NULL)
		{
			printf(" %c ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void append(char x)
{
	NODE *curr,*temp;

	temp       = (NODE*)malloc(sizeof(NODE));
	temp->data = x;
	temp->next = NULL;

	if(start == NULL)
		start = temp;
	else
	{
		curr = start;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

void add_beg(char x)
{
	NODE *temp,*curr;

	temp       = (NODE*)malloc(sizeof(NODE));
	temp->data = x;

	curr       = start;
	start      = temp;
	temp->next = curr;	
}


int main(int argc, char const *argv[])
{
	NODE obj1,obj2,obj3;

	obj1.data = 'A';
	obj2.data = 'B';
	obj3.data = 'C';

	start     = &obj1;
	obj1.next = &obj2;
	obj2.next = &obj3;
	obj3.next = NULL;

	display();
	append('D');	display();
	append('E');	display();
	append('F');	display();

	add_beg('G'); 	display();
	add_beg('H');	display();
	add_beg('I'); 	display();

	return 0;
}
