#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

static string int_to_string(int num)
{
	ostringstream outstr;
	outstr << num;
	string result = outstr.str();
	return result;
}

static bool my_less(const string &a, const string &b)
{
		string ab, ba;
		ab = a + b;
		ba = b + a;
		if(ab < ba)
			return true;
		return false;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> snum;

		for(vector<int>::const_iterator it = num.begin();it != num.end(); it++)
			snum.push_back(int_to_string(*it));

		sort(snum.rbegin(), snum.rend(), my_less);

		string result;
		for(vector<string>::const_iterator s_it = snum.begin();s_it != snum.end(); s_it++)
			result += *s_it;

		string::size_type zero = result.find_first_not_of("0");
		if(zero == string::npos ){
			result = "0";
		}
		return result;
    }
};


int main()
{
	class Solution s;
//	int arr[] = {3, 30, 34, 9, 5};
	int arr[100] = {0};
	arr[99] =2;
	vector<int> num(arr, arr + 100);

	string str = s.largestNumber(num);

	cout << str << endl;
	return 0;

}