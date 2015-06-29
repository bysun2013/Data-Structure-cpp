#include "intset.h"
#include <iostream>
using namespace std;

int main()
{
	IntSet s1, s2, s3, s4;
	int x;

	for(cin >> x; x != 0; cin >> x)
		s1.insert(x);//在s1 中插入元素

	for(cin >> x; x != 0; cin >> x)
		s2.insert(x);//在s2 中插入元素

	if(s1.IsEqual(s2))//比较s1 与s2 是否相等
		cout << " s1 is equal s2 ";
	else
		cout << " s1 is not equal s2 ";
	s3 = s3.union2(s1, s2);//求s1 与s2 的交

	s4 = s4.incorporate2(s1, s2);//求s1 与s2 的并

	cout << "\ns1:";
	s1.print();//输出s1 中的元素
	cout << "\ns2:";
	s2.print();
	cout << "\ns3:";
	s3.print();
	cout << "\ns4:";
	s4.print();
	return 0;
}