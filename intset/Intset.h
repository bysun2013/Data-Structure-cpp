#include <set>

class IntSet
{
public:
	IntSet();
	~IntSet(void);

	void insert(int x) { data.insert(x); }
	void erase(int x) { data.erase(x); }
	std::set<int>::const_iterator find (const int val) const{ return data.find(val);}
	bool IsEqual(const IntSet & set) const;
	//求两个set的交
	IntSet & union2(const IntSet & s1, const IntSet & s2);
	//求两个set的并
	IntSet & incorporate2(const IntSet & s1, const IntSet & s2);
	//打印
	void print(void) const;
	std::set<int>::const_iterator begin() const { return data.begin(); }
	std::set<int>::const_iterator end()const { return data.end(); }
private:
	std::set<int> data;
};