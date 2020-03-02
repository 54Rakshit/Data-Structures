#include <iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
};
template<class T>
class Queue
{
private:
	struct node<T> *head;
	struct node<T> *tail;

public:
	Queue();
	void Enqueue(T);
	T Dequeue();
	void Display();
};

template <class T>
Queue <T>::Queue()
{
	head =NULL;
	tail=NULL;
}

template <class T>
void Queue <T>::Enqueue(T no)
{
	struct node <T> *newn=NULL;
	newn=(struct node <T>*)malloc(sizeof(struct node<T>));

	newn->data=no;
	newn->next=NULL;

	if (head==NULL && tail==NULL)
	{
		head=newn;
		tail=newn;
	}
	else
	{
		tail->next=newn;
		tail=tail->next;
	}
}
template<class T>
T Queue<T>::Dequeue()
{
	if (head==NULL && tail==NULL)
	{
		return -1;
	}
	if (head==tail)
	{
		T temp;
		temp=head->data;
		free (head);
		head=NULL;
		tail=NULL;
		return temp;
	}
	else
	{
		T temp;
		temp=head->data;
		struct node<T> *ptr=NULL;
		ptr=head;
		head=head->next;
		free (ptr);
		return temp;
	}
}

template<class T>
void Queue<T>::Display()
{
	struct node<T> *temp=head;
	while (temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int main()
{
	Queue <int> iobj;
	Queue <char> cobj;

	iobj.Enqueue(11);
	iobj.Enqueue(21);
	iobj.Enqueue(51);
	iobj.Enqueue(101);

	

	iobj.Display();
	iobj.Dequeue();
	iobj.Display();

	cobj.Enqueue('p');
	cobj.Enqueue('q');
	cobj.Enqueue('r');
	cobj.Display();
	return 0;
}