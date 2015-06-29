#include <iostream>
#include "queue.h"

using namespace std;

template <class T>
queue<T>::queue(){
	front=new node<T>;
	front->next=NULL;
	front=rear;
}

template <class T>
queue<T>::~queue(){
	clearqueue();
	delete front;
}
template <class T>
void queue<T>::clearqueue(){
	node<T> *q,* p=front;
	while(p->next!=	NULL){
		q=p->next;
		delete p;
		p=q;
	}
	front->next=NULL;
	rear=front;
}

template <class T>
int queue<T>::getLength(){
	node<T> *p=front->next;
	int len=0;
	while(p!=NULL){
		p=p->next;
		len++;
	}
	return len;
}

template <class T>
bool queue<T>::isEmpty(){
	return front==rear;
}

template <class T>
bool queue<T>::push(T t){
	node<T> *p=new node<T>;
	p->data=t;
	p->next=NULL;
	rear->next=p;
	rear=p;
	return true;
}

template <class T>
bool queue<T>::pop(T &t){
	if(front==rear)
		return false;
	node<T> *p=front;
	front->next=p->next->next;
	t=p->data;
	return true;
}

template <class T>
void queue<T>::visit(){
	node<T> *p=front->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


int main()
{
	queue<int> Q;
	//cout<<Q.isEmpty()<<endl;
	//cout<<Q.getLength()<<":";
	//Q.visit();
	for(int i=0;i<5;i++)
	{
		Q.push(i);
		//cout<<Q.getLength()<<":";
		//Q.visit();
	}
	//Q.clearqueue();
	//cout<<Q.getLength()<<":";
	Q.visit();
	return 0;
}
#include <iostream>
#include "queue.h"

template <class T>
queue<T>::queue(){
	front=new node<T>;
	front->next=NULL;
	rear=front;
}

template <class T>
queue<T>::~queue(){
clearqueue();
delete front;
}

template <class T>
void queue<T>::clearqueue(){
	while(front->next!=NULL){
		node<T> *p=front;
		front=front->next;
		delete p;
	}
	front=rear;
}

template <class T>
int queue<T>::getLength(){

}