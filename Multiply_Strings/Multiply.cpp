#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1 == "0" || num2 == "0")
			return string("0");
		string rt(num1.size()+num2.size(), '0');
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for(size_t i = 0; i < num1.size(); i++){
			for(size_t j = 0; j < num2.size(); j++){
				int t = rt[i+j] - '0' + (num1[i]- '0')*(num2[j]-'0');
				rt[i+j] = t%10 + '0';
				rt[i+j+1] += t/10;
			}
		}

		reverse(rt.begin(), rt.end());
		size_t first = rt.find_first_not_of('0'); // string::npos

		return rt.substr(first);
    }
};


int main()
{
	Solution s;
	string n1, n2;
	
	while(cin >> n1 >> n2)
		cout << s.multiply(n1, n2) << endl;

	return 0;
}