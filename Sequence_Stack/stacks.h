//������Ϊʲô����һ��cpp��ִ��main����������.....
//��test.cpp��ִ�г������´���
//1>test.obj : error LNK2019: �޷��������ⲿ���� "public: __thiscall stack<int>::~stack<int>(void)" (??1?$stack@H@@QAE@XZ)���÷����ں��� _main �б�����
//1>test.obj : error LNK2019: �޷��������ⲿ���� "public: void __thiscall stack<int>::clearstack(void)" (?clearstack@?$stack@H@@QAEXXZ)���÷����ں��� _main �б�����


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