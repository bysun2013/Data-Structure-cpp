/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
  */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BSTIterator {
public:
    BSTIterator(TreeNode *root);

    /** @return whether we have a next smallest number */
    bool hasNext();

    /** @return the next smallest number */
    int next();
private:
	enum{LEFT, RIGHT};
	struct path{
		TreeNode *node;
		int direct;
	};
	TreeNode *base;
	TreeNode *cur;
	TreeNode *last;
	TreeNode *first;
	stack<path> route;
};

BSTIterator::BSTIterator(TreeNode *root):base(root)
{
	TreeNode *ptn;

	/*  set last */
	ptn = base;
	while(ptn){
		last = ptn;
		ptn = ptn->right;
	}

	cur = NULL;
}

/* if the BST is static , righest can be cached, it's O(1) */
bool BSTIterator::hasNext()
{
		if(base == NULL)
			return false;
		if(last == cur)
			return false;
		return true;
}

int BSTIterator::next()
{
        TreeNode *ptn, *next_node = cur;
		struct path p;

		if(cur == NULL){
			TreeNode *leftest;
			leftest = ptn = base;
			/* push node to stack, set cur */
			while(ptn){
				p.node = ptn;
				p.direct = LEFT;
				route.push(p);
				leftest = ptn;
				ptn = ptn->left;
			}
			route.pop();
			cur = leftest;
			return cur->val;
		}

		if(next_node->right){
			p.node = next_node;
			p.direct = RIGHT;
			route.push(p);
			ptn = next_node->right;
			while(ptn){
				p.node = ptn;
				p.direct = LEFT;
				route.push(p);
				next_node = ptn;
				ptn = ptn->left;
			}
			route.pop();
			cur = next_node;
			return next_node->val;
		}else{
			while(!route.empty() && route.top().direct == RIGHT)
				route.pop();
			if(route.empty())
				return -1;
			next_node = route.top().node;
			route.pop();
			cur = next_node;
			return next_node->val;
		}
}

static TreeNode* build_BST(vector<int> &v)
{
	TreeNode *root, *tmp, *parent;
	vector<int>::const_iterator it;
	root = parent = NULL;
	for(it = v.begin(); it != v.end(); it++){
		if(!root)
			root = new TreeNode(*it);
		else{
			parent = NULL;
			tmp = root;
			while(1){
				if(*it < tmp->val){
					if(tmp->left)
						tmp = tmp->left;
					else{
						tmp->left = new TreeNode(*it);
						break;
					}
				}else{
					if(tmp->right)
						tmp = tmp->right;
					else{
						tmp->right = new TreeNode(*it);
						break;			
					}
				}
			}
		}
	}
	return root;
}

static int visit(const TreeNode * node)
{
	cout << node->val << "\t";
	return 0;
}
void traverse_inorder_recursive(TreeNode *root, int (*visit)(const TreeNode *))
{
	if(!root)
		return;

	traverse_inorder_recursive(root->left, visit);
	visit(root);
	traverse_inorder_recursive(root->right, visit);
}


int main()
{
	TreeNode *root;
	int arr[] = {9,3,200,2,4,5,1};
	vector<int> v(arr, arr+7);

	cout << "build bst"<< endl;
	root = build_BST(v);

	traverse_inorder_recursive(root, visit);
	cout << endl;

	cout << "build iterator"<< endl;
	BSTIterator i = BSTIterator(root);

	cout << "print next"<< endl;
	while (i.hasNext()) 
		cout << i.next();
	cout << endl;
	return 0;
}