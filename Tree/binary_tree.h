#include <string>
using namespace std;

static int i=0; //带与不带static有什么区别！？
enum Flags{Left,Right};

template <class T>
struct Node{
	T data;
	Node<T> *left,*right;
};

template <class T>
struct elem{
	Node<T> *node;
	Flags flag;
};

template <class T>
class tree{
private:
	Node<T>* root;
public:
	tree();
	tree(string s);
	Node<T>* create();
	Node<T>* create(string s);
	~tree();
	void release(Node<T>* root);
	int getDepth(Node<T>* root);
	Node<T>* getRoot();
	Node<T>* getParent(Node<T>* p);

void preTraverse(Node<T>* root);
void midTraverse(Node<T>* root);
void posTraverse(Node<T>* root);
void levTraverse(Node<T>* root);
bool delchild(Node<T>* root,Flags flag);

};