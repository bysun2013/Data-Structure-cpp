#include <iostream>
#include <bitset>

using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b((long)n);
		bitset<32> result;
		for(int i=0;i<32;i++){
			result[i] = b[31 - i];
		}
		return result.to_ulong();
    }
};

int main()
{
	Solution s;
	cout << s.reverseBits(43261596) << endl;
	cout << s.reverseBits(1) <<endl;
	return 0;
}