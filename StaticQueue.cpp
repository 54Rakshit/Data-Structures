#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
	T *arr;
	int front;
	int rear;
	int size;
public:
	Queue(int);
	~Queue();
	void Enqueue(T);
	T Dequeue();
	void Display();
};

template <class T>
Queue<T>::Queue(int value)
{
	this->size=value;
	this->arr=new T[size];
	this->front=-1;
	this->rear=-1;
}

template <class T>
Queue<T>::~Queue()
{
	delete[]arr;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
	if (front==0 && rear==(size-1))
	{
		cout<<"Queue is full"<<endl;
		return;
	}

	else if(front==-1)
	{
		front=0;
		rear=0;
		arr[rear]=no;
	}

	else if (rear=size-1 && front!=0)
	{
		rear=0;
		arr[rear]=no;
	}
	else
	{
		rear++;
		arr[rear]=no;
	}
}

template <class T>
T Queue<T>::Dequeue()
{
	T temp;
	if (front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	temp=arr[front];

	if (rear==front)
	{
		front=-1;
		rear=-1;
	}
	else if (rear=size-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
	return temp;
}
template <class T>
void Queue<T>::Display()
{
	int i=0;
	if (front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		for (i=front; i!=rear; i=(i+1)%size)
		{
			cout<<arr[i]<<endl;
		}
		cout<<arr[i]<<endl;
	}
}




int main()
{
	Queue <int> iobj(5);
	Queue <char> cobj(5);

	iobj.Enqueue(11);
	iobj.Enqueue(21);
	iobj.Enqueue(51);
	iobj.Enqueue(101);
	iobj.Enqueue(121);

	iobj.Dequeue();
	iobj.Dequeue();

	iobj.Display();
	return 0;
}
