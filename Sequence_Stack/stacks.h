//不明白为什么在另一个cpp中执行main方法不可以.....
//在test.cpp中执行出现如下错误：
//1>test.obj : error LNK2019: 无法解析的外部符号 "public: __thiscall stack<int>::~stack<int>(void)" (??1?$stack@H@@QAE@XZ)，该符号在函数 _main 中被引用
//1>test.obj : error LNK2019: 无法解析的外部符号 "public: void __thiscall stack<int>::clearstack(void)" (?clearstack@?$stack@H@@QAEXXZ)，该符号在函数 _main 中被引用


using namespace std;

template <class T>
class stack{
private:
	T* top;
	T* base;
	int size;
public:
	stack(int k=1);
	~stack();
	void clearstack();
	bool pop(T& t);
	bool push(T t);
	void print();
	int getLength();

};