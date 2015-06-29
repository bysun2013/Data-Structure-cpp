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
	//������set�Ľ�
	IntSet & union2(const IntSet & s1, const IntSet & s2);
	//������set�Ĳ�
	IntSet & incorporate2(const IntSet & s1, const IntSet & s2);
	//��ӡ
	void print(void) const;
	std::set<int>::const_iterator begin() const { return data.begin(); }
	std::set<int>::const_iterator end()const { return data.end(); }
private:
	std::set<int> data;
};