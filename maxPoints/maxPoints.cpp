#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for a point.
  */
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int max_g = 0;
		int size = points.size();
		if(size <= 2)
			return size;
		for(int i = 0;i < size; i++){
			map<double, int> count_l;
			int max_l = 0, same_point = 1;
			double x = points[i].x, y = points[i].y;
			for(int j = i + 1; j < size; j++){
				double slope;
				if(x - points[j].x == 0){
					if(y - points[j].y == 0){
						same_point++;
						continue;
					}else
						slope = INT_MAX;
				}else
					slope = (y - points[j].y)/(x - points[j].x);
				count_l[slope]++;
				if(count_l[slope] > max_l)
					max_l = count_l[slope];
			}
			if(max_l + same_point > max_g)
				max_g = max_l + same_point;
		}
		return max_g;
    }
};

static const int NUM = 4;
int main()
{
	Solution s;
	Point p[NUM] = { 
		Point(),
		Point(),
		Point(),
		Point(),
	};
	vector<Point> points(p, p+NUM);

	/*
	for(int i =0; i<10; i++){
		p.x = i;
		p.y = i;
		points.push_back(p);	
	}
	*/
	cout << s.maxPoints(points) << endl;
	return 0;
}