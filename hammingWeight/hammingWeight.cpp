#include <iostream>
#include <bitset>

typedef int uint32_t;

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;

		while(n){
			count++;
			n = n & (n-1);
		}
		return count;
    }
};

int main()
{
	class Solution s;
	uint32_t num;

	while((cin >> num) && num){
		bitset<32> bnum(num);
		cout  << bnum << endl;
		cout << s.hammingWeight(num) << endl;
	}
	return 0;
}