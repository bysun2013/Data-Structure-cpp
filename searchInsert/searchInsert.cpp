#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int i;
		if(n <= 0)
			return 0;
		for(i = 0; i < n && A[i] < target; i++)
			;
		return i;
    }
};

int main()
{
	/* 这个题太简单了，不需要测试 */
}