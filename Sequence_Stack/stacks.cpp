#include <iostream>
#include "stacks.h"

using namespace std;

template <class T>
stack<T>::stack(int k = 1){
	base=new T[k];
	top=base;
	size=k;
}

template <class T>
stack<T>::~stack(){
	delete []base;
}

template <class T>
void stack<T>::clearstack(){
	top=base;
}

template <class T>
int stack<T>::getLength(){
	return (top-base);
}

template <class T>
bool stack<T>::push(T t){
	if(top-base==size){
		T* newbase=new T[2*size];
		for(int i=0;i<top-base;i++)
			*(newbase+i)=*(base+i);
		delete []base;
		base=newbase;
		top=base+size;
		size=2*size;
	}
	*top++=t;
	return true;
}

template <class T>
bool stack<T>::pop(T& t){
	if(top==base)
		return false;
t=*(--top);
return true;
}

template <class T>
void stack<T>::print(){
	for(int i=0;i<top-base;i++){
		cout<<*(base+i)<<" ";
	}
	cout<<endl;
}





int main()
{	
	stack <int> La;
	cout<<La.getLength()<<endl;
	for(int i=1;i<5;i++)
		La.push(i);
	cout<<La.getLength()<<",";
	La.print();
	cout<<endl;
	int e;
	for(int i=1;i<5;i++)
	{
		La.pop(e);
		La.print();
	}
	for(int i=1;i<5;i++)
		La.push(i);
	La.print();
	La.clearstack();
	cout<<La.getLength();
	return 0;
}