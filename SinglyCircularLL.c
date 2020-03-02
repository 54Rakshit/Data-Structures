#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;
	struct Node* next;
}NODE, *PNODE,**PPNODE;

void InsertFirst(PPNODE,PPNODE,int);
void Display(PNODE,PNODE);
int Count(PNODE,PNODE);
void InsertLast(PPNODE,PPNODE,int);
void DeleteFirst(PPNODE,PPNODE);
void DeleteLast(PPNODE,PPNODE);
void InsertAtPos(PPNODE,PPNODE,int,int);
void DeleteAtPos(PPNODE,PPNODE,int);

int main()
{
	PNODE head=NULL;
	PNODE tail=NULL;
	int Ret=0;

	InsertFirst(&head,&tail,51);
	InsertFirst(&head,&tail,21);
	InsertFirst(&head,&tail,11);

	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

	InsertLast(&head,&tail,42);
	InsertLast(&head,&tail,66);
	InsertLast(&head,&tail,72);
	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

	DeleteFirst(&head,&tail);
	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

	DeleteLast(&head,&tail);
	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

	InsertAtPos(&head, &tail, 45,2);
	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

	DeleteAtPos(&head, &tail,2);
	Display(head,tail);
	Ret=Count(head,tail);
	printf("The Count is %d\n",Ret);

}

void InsertFirst(PPNODE first, PPNODE last, int no)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if ((*first==NULL)&&(*last==NULL))
	{
		*first=newn;
		*last=newn;
	}
	else
	{
		newn->next=*first;
		*first=newn;
	}
	(*last)->next=(*first);
}

void Display(PNODE first, PNODE last)
{
	if ((first==NULL)&&(last==NULL))
	{
		return;
	}
	do
	{
		printf("%d\n",first->data);
		first=first->next;
	}while(first!=last->next);
}

int Count(PNODE first,PNODE last)
{
	int Cnt=0;

	if ((first==NULL)&&(last==NULL))
	{
		return Cnt;
	}
	do
	{
		Cnt++;
		first=first->next;
	}while(first!=last->next);
	return Cnt;
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if ((*first==NULL)&&(*last==NULL))
	{
		*first=newn;
		*last=newn;
	}
	else
	{
		(*last)->next=newn;
		(*last)=(*last)->next;
	}
	(*last)->next=(*first);
}


void DeleteFirst(PPNODE first, PPNODE last)
{
	if ((*first==NULL)&&(*last==NULL))
	{
		return;
	}
	else if (*first==*last)
	{
		free(*first);
		*first=NULL;
		*last=NULL;
	}
	else
	{
		(*first)=(*first)->next;
		free((*last)->next);
		(*last)->next=(*first);
	}
}


void DeleteLast(PPNODE first, PPNODE last)
{
	PNODE temp=(*first);

	if ((*first==NULL)&&(*last==NULL))
	{
		return;
	}
	else if (*first==*last)
	{
		free(*first);
		*first=NULL;
		*last=NULL;
	}
	else
	{
		do
		{
			temp=temp->next;
		}while(temp->next!=(*last));
		free (*last);
		(*last)=temp;
		(*last)->next=(*first);
	}
}


void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
	int i=0, size=0;
	PNODE temp=NULL;

	PNODE newn=NULL;

	size=Count(*first, *last);

	if ((pos<1)||(pos>size+1))
	{
		return;
	}

	if (pos==1)
	{
		InsertFirst(first,last,no);
	}
	else if (pos==size)
	{
		InsertLast(first,last,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));

		temp=(*first);

		newn->data=no;
		newn->next=NULL;

		for (i=1; i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
	int i=0, size=0;
	PNODE temp=NULL;
	PNODE target=NULL;

	PNODE newn=NULL;

	size=Count(*first, *last);

	if ((pos<1)||(pos>size+1))
	{
		return;
	}

	if (pos==1)
	{
		DeleteFirst(first,last);
	}
	else if (pos==size)
	{
		DeleteLast(first,last);
	}
	else
	{
		temp=(*first);

		for (i=1; i<pos-1; i++)
		{
			temp=temp->next;
		}
		target=temp->next;

		temp->next=target->next;
		free (target);
	}
}