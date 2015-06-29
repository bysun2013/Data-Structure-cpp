#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

static string my_int_to_string(long long a)
{
	ostringstream oss;
	oss << a;
	return oss.str();
}

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		return my_fraction_To_Decimal(numerator, denominator);
	}
private:
    string my_fraction_To_Decimal(long long numerator, long long denominator) {
        string s;
		if(numerator == 0)
			return "0";
		if(denominator == 0)
			return "";
		if((numerator < 0) ^ (denominator < 0))
			s += "-";

		numerator = abs(numerator);
		denominator = abs(denominator);

		s += my_int_to_string(numerator/denominator);
		long long  remainder = numerator % denominator;

		if(remainder == 0)
			return s;

		s += ".";
		/* 小数点部分 */
		map<long long, int> mrd;
		int digit;
		long long r;
		while(remainder){
			if(mrd.find(remainder) != mrd.end()){
				s.insert(mrd[remainder], 1, '(');
				s += ")";
				break;
			}
			mrd[remainder] = s.size();
			r = remainder * 10;
			digit = r / denominator;
			s += my_int_to_string(digit);
			remainder = r % denominator;
		}
		return s;
    }
};

int main()
{
	Solution s;
	
	cout << s.fractionToDecimal(1, 333)<< endl;
	cout << s.fractionToDecimal(2, 1)<< endl;
	cout << s.fractionToDecimal(2, 3)<<endl;
	cout << s.fractionToDecimal(-2147483648, -1)<<endl;
	cout << s.fractionToDecimal(-2147483648, 1)<<endl;
	cout << s.fractionToDecimal(2147483647, -1)<<endl;
	cout << s.fractionToDecimal(-1, -2147483648)<<endl;
	return 0;
}