#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/* 10 ms */
    int findMin_slow(vector<int> &num) {
		vector<int>::const_iterator it;
		int last = *(num.begin());

		for(it=num.begin() + 1; it!=num.end(); it++)
			if(*it < last)
				break;

		if(it == num.end())
			return num[0];
		return *it;
    }
	/* 6 ms */
	int findMin(vector<int> &num){
		int len = num.size();
		if(len <= 1 || num[0] < num[len-1])
			return num[0];

		int low = 0, high = len -1;
		while(low < high){
			int middle = (low+high)/2;
			if(num[middle] < num[low]){
				if(middle > 0 && num[middle] < num[middle -1])
					return num[middle];
				high = middle - 1;
			}else if(num[middle] > num[high]){
				if(middle < len -1 && num[middle] > num[middle+1])
					return num[middle + 1];
				low = middle + 1;
			}
		}
		return -1;
	}
};

int main()
{
	int a[] = {2,3,4,5, 6, 7, 8};
	vector<int> num(a, a+7);
	Solution s;
	cout <<  s.findMin(num) << endl;
	
	return 0;
}