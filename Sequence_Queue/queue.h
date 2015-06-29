using namespace std;

template <class T>
struct node{
	T data;
	node<T> *next;
};
template <class T>
class queue{
private:
	node<T> *front,*rear;
public:
	queue();
	~queue();
	void clearqueue();
	int getLength();
	bool push(T t);
	bool pop(T& t);
	bool isEmpty();
	void visit();

};