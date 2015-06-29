#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "binary_tree.h"
using namespace std;

template <class T>
tree<T>::tree(){
	root=create();
}

template <class T>
tree<T>::tree(string s){
	root=create(s);
}

template <class T>
tree<T>::~tree(){
	release(root);
}


template <class T>
Node<T>* tree<T>::create(){
	Node<T>* p;
	T t;
	cout<<"Please input the data: ";
	cin>>t;
	if(t=='#')
		p=NULL;
	else{
		p=new Node<T>;
		p->data=t;
		p->left=create();
		p->right=create();
	}
	return p;
}

template <class T>
Node<T>* tree<T>::create(string s){
	Node<T>* p;
	if(s[i]=='#'){
		p=NULL;
		i++;
	}else{
		p=new Node<T>;
		p->data=s[i];
		i++;
		p->left=create(s);
		p->right=create(s);
	}
	return p;
}

template <class T>
void tree<T>::release(Node<T> *root){
	if(root!=NULL){
		release(root->left);
		release(root->right);
		delete root;
	}
}

template <class T>
Node<T>* tree<T>::getRoot(){
	return root;
}

template <class T>
int tree<T>::getDepth(Node<T>* root){
	int i,j;
	if(root==NULL)
		return 0;
	else{
		i=getDepth(root->left);
		j=getDepth(root->right);
		return i>j?i+1:j+1;

	}
}

template <class T>
Node<T>* tree<T>::getParent(Node<T> *p){
	queue<Node<T> *> q;
	Node<T> *node;
	q.push(root);
	while(!q.empty()){
		node=q.front();
		q.pop();
		if(node->left&&node->left==p||node->right&&node->right==p){
			return node;
			break;
		}
		else{
			if(node->left!=NULL)
				q.push(node->left);
			if(node->right!=NULL)
				q.push(node->right);
		}
	}
	return NULL;
}

template <class T>
void tree<T>::preTraverse(Node<T> *root){
	stack<Node<T> *> s;
	Node<T> * p=root;
	cout<<"The PreTraverse Sequence is :";
	while(!s.empty()||p!=NULL){
		while(p!=NULL){
			cout<<p->data<<" ";
			s.push(p);
			p=p->left;
		}
		p=s.top();
		s.pop();
		p=p->right;
	}
	cout<<endl;
}

template <class T>
void tree<T>::midTraverse(Node<T> *root){
	stack<Node<T> *> s;
	Node<T> * p=root;
	cout<<"The MidTraverse Sequence is :";
	while(!s.empty()||p!=NULL){
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
		p=s.top();
		cout<<p->data<<" ";
		s.pop();
		p=p->right;
	}
	cout<<endl;
}

//重中之重！难点之处，仔细琢磨！
template <class T>
void tree<T>::posTraverse(Node<T> *root){
	stack< elem<T> >s;
	elem<T> e;
	Node<T> *p;
	p=root;
		cout<<"The posTraverse Sequence is: "; 
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			e.flag=Left;
			e.node=p;
			s.push(e);
			p=p->left;
		}
		e=s.top();
		s.pop();
		p=e.node;
		if(e.flag==Left)
		{
			e.flag=Right;
			s.push(e);
			p=p->right;
		}
		else
		{
			if(e.flag==Right)
			{
			cout<<e.node->data<<" ";
			p=NULL;
			}
		}
	}
	cout<<endl;
}

template <class T>
void tree<T>::levTraverse(Node<T> *root){
	queue<Node<T>*> q;
	Node<T>* p=root;
	q.push(p);
	cout<<"The LevTraverse Sequence is: ";
	while(!q.empty()){
		p=q.front();
		q.pop();
		cout<<p->data<<" ";
		if(p->left!=NULL)
			q.push(p->left);
		if(p->right!=NULL)
			q.push(p->right);
	}
	cout<<endl;
}

template <class T>
bool tree<T>::delchild(Node<T> *root, Flags flag){
	if(root!=NULL){
		if(flag==Left){
			this->release(root->left);
			root->left=NULL;
			return true;
		}else{
			this->release(root->right);
			root->right=NULL;
			return true;
		}
	}
	return false;
}



int main(){
	//tree<char> t;
	tree<char> t("ABE###CD##F##");
	//tree<double> t;         出现错误，无法解释！char型正常运行，int、double均无法运行！
	//Node<double>* node;
	int depth=t.getDepth(t.getRoot());
	cout<<"The Depth of This Tree is: "<<depth<<endl;
	Node<char>* node;
	node=t.getRoot();
	cout<<"The Root is: "<<node->data<<endl; 
	t.preTraverse(t.getRoot());
	t.midTraverse(t.getRoot());
	t.levTraverse(t.getRoot());
	t.posTraverse(t.getRoot());
	node=t.getParent(t.getRoot()->right);
	cout<<"The Parent of "<<t.getRoot()->right->data<<" is:"<<node->data;
	cout<<endl;
	cout<<"After Delete Left Tree: "<<endl;
	//if(t.delchild(t.getRoot()->left->right,Right))  //Wrong
	if(t.delchild(t.getRoot(),Left))  //Correct!
	{
		t.preTraverse(t.getRoot());
		t.midTraverse(t.getRoot());
		t.levTraverse(t.getRoot());
	}else
		cout<<"Failed!"<<endl;
	return 0;
}