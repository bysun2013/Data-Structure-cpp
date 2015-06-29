#include "Intset.h"
#include <iostream>
#include <set>
using namespace std;

IntSet::IntSet(void)
{
}

IntSet::~IntSet(void)
{
}

bool IntSet::IsEqual(const IntSet & my_set) const
{
	set<int>::const_iterator it1, it2;
	it1 =begin();
	it2 = my_set.begin();
	while(it1 != end()){
		if(*it1 != *it2)
			return false;
		it1++, it2++;
	}

	if(it2 == my_set.end())
		return true;
	return false;
}

//求两个set的交
IntSet & IntSet::union2(const IntSet & s1, const IntSet & s2)
{
	set<int>::const_iterator it;

	for(it = s2.begin();it != s2.end();it++){
		if(s1.find(*it) != s1.end())
			insert(*it);
	}

	return *this;
}

//求两个set的并
IntSet & IntSet::incorporate2(const IntSet & s1, const IntSet & s2)
{
	set<int>::const_iterator it;
	
	for(it = s1.begin();it != s1.end();it++)
		insert(*it);
	
	for(it = s2.begin();it != s2.end();it++)
		insert(*it);

	return *this;
}

void IntSet::print(void) const
{
	set<int>::const_iterator it;
	for(it = begin();it != end();it++){
		cout << *it << "\t";
	}
	cout << endl;
}