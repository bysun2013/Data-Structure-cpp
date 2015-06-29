#include "intset.h"
#include <iostream>
using namespace std;

int main()
{
	IntSet s1, s2, s3, s4;
	int x;

	for(cin >> x; x != 0; cin >> x)
		s1.insert(x);//��s1 �в���Ԫ��

	for(cin >> x; x != 0; cin >> x)
		s2.insert(x);//��s2 �в���Ԫ��

	if(s1.IsEqual(s2))//�Ƚ�s1 ��s2 �Ƿ����
		cout << " s1 is equal s2 ";
	else
		cout << " s1 is not equal s2 ";
	s3 = s3.union2(s1, s2);//��s1 ��s2 �Ľ�

	s4 = s4.incorporate2(s1, s2);//��s1 ��s2 �Ĳ�

	cout << "\ns1:";
	s1.print();//���s1 �е�Ԫ��
	cout << "\ns2:";
	s2.print();
	cout << "\ns3:";
	s3.print();
	cout << "\ns4:";
	s4.print();
	return 0;
}