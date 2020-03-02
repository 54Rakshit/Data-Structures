#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node* next;
};



typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE, int);
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE, int, int);
void DeleteAtPos(PPNODE,int);

void InsertFirst(PPNODE first, int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if (*first==NULL)
	{
		*first=newn;
	}

	else
	{
		newn->next= *first;
		*first=newn;
	}
}

void Display(PNODE first)
{
	while (first!=NULL)
	{
		printf("%d \n \n",first->data );
		first = first->next;
	}
}

int Count(PNODE first)
{
	int Cnt=0;
	while (first!=NULL)
	{
		Cnt++;
		first=first->next;
	}
	return Cnt;
}


void InsertLast(PPNODE first, int no)
{
	PNODE newn=NULL;
	PNODE temp=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if (*first==NULL)
	{
		*first=newn;
	}

	else
	{
		temp=*first;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}

void DeleteFirst(PPNODE first)
{
	PNODE temp=*first;

	if (*first!=NULL)
	{
		*first=(*first)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE first)
{
	PNODE temp=NULL;

	if (*first==NULL)
	{
		return;
	}

	else if ((*first)->next==NULL)
	{
		free (*first);
		*first=NULL;
	}
	else
	{
		temp=*first;

		while (temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

void InsertAtPos(PPNODE first, int no, int pos)
{
	int size=0, Cnt=0;
	PNODE temp=*first;
	size=Count(*first);

	if ((pos<1)||(pos>size+1))
	{
		return;
	}

	if (pos==1)
	{
		InsertFirst(first,no);
	}
	else if (pos==size+1)
	{
		InsertLast(first,no);
	}
	else
	{
		PNODE newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=no;
		newn->next=NULL;

		for (Cnt=1; Cnt<pos-1; Cnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE first, int pos)
{
	PNODE temp=*first;
	PNODE target=NULL;

	int Cnt=0;
	int size=Count(*first);

	if ((pos<1)||(pos>size))
	{
		return;
	}

	if(pos==1)
	{
		DeleteFirst(first);
	}
	else if(pos==size)
	{
		DeleteLast(first);
	}
	else
	{
		for (Cnt=1; Cnt<pos-1;Cnt++)
		{
			temp=temp->next;
		}
		target=temp->next;

		temp->next=target->next;
		free(target);
	}
}





int main()
{
	PNODE head=NULL;
	int Ret=0;

	InsertFirst(&head,30);
	InsertFirst(&head,20);
	InsertFirst(&head,10); 
	printf("Inserting at first: \n");
	Display(head);

	Ret=Count(head);
	printf("Count is: %d  \n\n ", Ret);

	InsertLast(&head,40);
	InsertLast(&head,50);
	printf("Inserting at last: \n");
	Display(head);

	DeleteFirst(&head);
	printf("After deleting first Node: \n");
	Display(head);

	DeleteLast(&head);
	printf("After deleting last Node: \n");
	Display(head);

	InsertAtPos(&head,50,3);
	printf("After inserting at position: \n");
	Display(head);

	DeleteAtPos(&head, 2);
	printf("After deleting at position: \n");
	Display(head);

}
