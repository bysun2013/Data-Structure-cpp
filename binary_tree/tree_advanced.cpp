/**
* 二叉树的三种遍历，先序遍历、中序遍历、后序遍历
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class binary_node{
public:
	binary_node *left, *right;
	T data;
	int flag;

	binary_node():left(NULL),right(NULL){}
	binary_node(const T & value):left(NULL),right(NULL),data(value){}
};

template <typename T>
class binary_tree{
public:
	binary_node<T> *base;
	binary_tree():base(NULL){}
	int build_tree(vector<T> &);

	/* 非递归遍历算法 */
	void traverse_preorder(binary_node<T> *root, int (*visit)(const binary_node<T> *));
	void traverse_inorder(binary_node<T> *root, int (*visit)(const binary_node<T> *));
	void traverse_postorder(binary_node<T> *root, int (*visit)(const binary_node<T> *));
	
	/* 递归遍历算法 */
	void traverse_preorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *));
	void traverse_inorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *));
	void traverse_postorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *));
};

template <typename T>
static int visit(const binary_node<T> * node)
{
	cout << node->data << " ";
	return 0;
}

template <typename T>
int binary_tree<T>::build_tree(vector<T> &v)
{
	binary_node<T> *node;
	vector<T>::const_iterator it;
	for(it = v.begin(); it != v.end(); it++){
		node = new binary_node<T>(*it);
		if(!node){
			cerr << "malloc error"<<endl;
			return -1;
		}

		if(!base){
			base = node;
		}else{
			binary_node<T> *tmp;
			T t = *it;
			tmp = base;

			while(1){
				if(t < tmp->data){
					if(tmp->left == NULL){
						tmp->left = node;
						break;
					}else
						tmp = tmp->left;
				}else{
					if(tmp->right == NULL){
						tmp->right = node;
						break;
					}else
						tmp = tmp->right;
				}
			}
		}
	}
	return 0;
}

/* 非递归先序遍历 */
template <typename T>
void binary_tree<T>::traverse_preorder(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	const binary_node<T> *node;
	stack<binary_node<T> *> s;
	
	s.push(root);
	while(!s.empty() && (node = s.top())){
		s.pop();
		visit(node);
		if(node->right)
			s.push(node->right);
		if(node->left)
			s.push(node->left);
	}
}

/* 非递归中序遍历 */
template <typename T>
void binary_tree<T>::traverse_inorder(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	binary_node<	T> *node = root;
	stack<binary_node<T> *> s;

	while(node){
		s.push(node);
		node = node->left;
	}
	
	while(!s.empty() && (node = s.top())){
		s.pop();
		visit(node);
		node = node->right;
		while(node){
			s.push(node);
			node = node->left;
		}
	}
}

/* 非递归后序遍历 */
template <typename T>
void binary_tree<T>::traverse_postorder(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	binary_node<T> *node;
	stack<binary_node<T> *> s;

	s.push(root);
	while(!s.empty()){
		while(node = s.top()){
			node->flag = 1;
			s.push(node->left);
		}
		s.pop();
		
		if(!s.empty()){
			node = s.top();
			
			if(node->flag == 1){
				s.push(node->right);
				node->flag = 2;
			}else if(node->flag == 2){
				s.pop();
				visit(node);
				s.push(NULL);
			}
		}
	}
}

/* 递归先序遍历 */
template <typename T>
void binary_tree<T>::traverse_preorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	if(!root)
		return;

	visit(root);
	traverse_preorder_recursive(root->left, visit);
	traverse_preorder_recursive(root->right, visit);
}

/* 递归中序遍历 */
template <typename T>
void binary_tree<T>::traverse_inorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	if(!root)
		return;

	traverse_inorder_recursive(root->left, visit);
	visit(root);
	traverse_inorder_recursive(root->right, visit);
}

/* 递归后序遍历 */
template <typename T>
void binary_tree<T>::traverse_postorder_recursive(binary_node<T> *root, int (*visit)(const binary_node<T> *))
{
	if(!root)
		return;

	traverse_postorder_recursive(root->left, visit);
	traverse_postorder_recursive(root->right, visit);
	visit(root);
}


int main()
{
	binary_tree<char> bt;
//	T arr[] = {7, 4, 10, 1, 5, -1, 2, 9, 13, 18};
	char arr[] = {'u', 'k', 'i', 'B', 'Y', 'P', ';', 'Q', 'S', 'a'};
	vector<char> v(arr, arr+10);

	bt.build_tree(v);

	cout << "Preorder traverse recursive version:\n";
	bt.traverse_preorder_recursive(bt.base, visit);
	cout << endl;

	cout << "Preorder traverse NON-recursive version:\n";
	bt.traverse_preorder(bt.base, visit);
	cout << endl;

	cout << "Inorder traverse recursive version:\n";
	bt.traverse_inorder_recursive(bt.base, visit);
	cout << endl;

	cout << "Inorder traverse NON-recursive version:\n";
	bt.traverse_inorder(bt.base, visit);
	cout << endl;

	cout << "Postorder traverse recursive version:\n";
	bt.traverse_postorder_recursive(bt.base, visit);
	cout << endl;

	cout << "Postorder traverse NON-recursive version:\n";
	bt.traverse_postorder(bt.base, visit);
	cout << endl;

	cout << "==================================="<<endl;
	binary_tree<int> bt_int;
	int arr_int[] = {7, 4, 10, 1, 5, -1, 2, 9, 13, 18};
	vector<int> v_int(arr_int, arr_int+10);

	bt_int.build_tree(v_int);

	cout << "Preorder traverse recursive version:\n";
	bt_int.traverse_preorder_recursive(bt_int.base, visit);
	cout << endl;

	cout << "Preorder traverse NON-recursive version:\n";
	bt_int.traverse_preorder(bt_int.base, visit);
	cout << endl;

	cout << "Inorder traverse recursive version:\n";
	bt_int.traverse_inorder_recursive(bt_int.base, visit);
	cout << endl;

	cout << "Inorder traverse NON-recursive version:\n";
	bt_int.traverse_inorder(bt_int.base, visit);
	cout << endl;

	cout << "Postorder traverse recursive version:\n";
	bt_int.traverse_postorder_recursive(bt_int.base, visit);
	cout << endl;

	cout << "Postorder traverse NON-recursive version:\n";
	bt_int.traverse_postorder(bt_int.base, visit);
	cout << endl;
	return 0;
}