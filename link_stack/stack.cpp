#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T> *next;
};

template <class T>
class stack{
private:
	node<T>* top;
	int length;
public:
	stack(){
		//top=new node<T>;
		top=NULL;
		length=0;
	}
	~stack(){
		clearstack();
	}
	void clearstack(){ 
		node<T> *p;
		node<T> *q;
		p=top;
		while(p!=NULL){
			q=p->next;
			delete p;
			p=q;
		}
		top=NULL;
	}
	int getLength(){
		int len=0;
		node<T> *p;
		p=top;
		while(p!=NULL){
			p=p->next;
			len++;
		}
		return len;
	}
	bool push(T e){
		node<T> *p=new node<T>;
		p->data=e;
		p->next=top;
		top=p;
		length++;
		return true;
	}
	bool pop(T& e){
		if(top==NULL)
			return false;
		node<T> *p;
		p=top;
		top=p->next;
		e=p->data;
		length--;
		return true;
	}
	void print(){
		node<T> *p=top;
		while(p!=NULL){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};



int main()
{	
	stack <int> La;
	cout<<"The length of stack is: "<<La.getLength()<<endl;
	for(int i=1;i<5;i++)
		La.push(i);
	cout<<"After push 1-4, The length of stack is: "<<La.getLength()<<",  ";
	La.print();
	int e;
	for(int i=1;i<5;i++)
	{
		La.pop(e);
		cout<<"after pop "<<e<<" :";
		La.print();
	}
	for(int i=1;i<5;i++)
		La.push(i);
	cout<<"after push 1-4 : ";
	La.print();
	La.clearstack();
	cout<<" After clear the stack, The length of stack is: "<<La.getLength()<<endl;
	return 0;
}
