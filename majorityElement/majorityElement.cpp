#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
		return num[(num.size()+1)/2 - 1];
    }
};

int main()
{
	return 0;
}