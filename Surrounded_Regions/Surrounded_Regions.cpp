/**
	https://leetcode.com/problems/surrounded-regions/
	这个题目使用BFS和DFS两种方式实现
	因为DFS使用递归调用，在数据很大的时候会出现栈溢出
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution_bfs {
private:
	struct point{
		int x;
		int y;
		point(int a, int b):x(a),y(b){}
	};
	void bfs(vector<vector<char> > &board, int i, int j){
		queue<point> q;
		q.push(point(i, j));
		int width = board[0].size();
		int height = board.size();

		while(!q.empty()){
			point f = q.front();
			q.pop();
			int x = f.x;
			int y = f.y;
			if(x < 0 || x >= height || y < 0 || y >= width || board[x][y] != 'O')
				continue;
			board[x][y] = '#';
			q.push(point(x+1, y));
			q.push(point(x-1, y));
			q.push(point(x, y-1));
			q.push(point(x, y+1));
		}
	}
public:
    void solve(vector<vector<char> > &board) {
		if(board.empty())
			return;

		int height = board.size();
 		int width = board[0].size();

		for(int i =0;i<width; i++){
			if(board[0][i] == 'O')
				bfs(board, 0, i);
			if(board[height - 1][i] == 'O')
				bfs(board, height-1, i);
		}

		for(int j =0;j<height; j++){
			if(board[j][0] == 'O')
				bfs(board, j, 0);
			if(board[j][width - 1] == 'O')
				bfs(board, j, width-1);
		}
		for(int j =0;j<height; j++){
			for(int i =0;i<width; i++){
				if(board[j][i] == 'O')
					board[j][i] = 'X';
				if(board[j][i] == '#')
					board[j][i] = 'O';
			}
		}
    }

	void show(vector<vector<char> > &board){
		if(board.empty())
			return;

		int height = board.size();
 		int width = board[0].size();

		for(int i = 0; i < height;i++){
			for(int j = 0; j< width;j++){
				cout << board[i][j];
			}
			cout << endl;
		}
	}
};


class Solution_dfs {
private:
	struct point{
		int x;
		int y;
		point(int a, int b):x(a),y(b){}
	};
	void dfs(vector<vector<char> > &board, int x, int y){
		int width = board[0].size();
		int height = board.size();

		if(x < 0 || x >= height || y < 0 || y >= width || board[x][y] != 'O')
			return;
		board[x][y] = '#';
		dfs(board, x-1, y);
		dfs(board, x+1, y);
		dfs(board, x, y-1);
		dfs(board, x, y+1);
	}

public:
    void solve(vector<vector<char> > &board) {
		if(board.empty())
			return;

		int height = board.size();
 		int width = board[0].size();

		for(int i =0;i<width; i++){
				dfs(board, 0, i);
				dfs(board, height-1, i);
		}

		for(int j =0;j<height; j++){
				dfs(board, j, 0);
				dfs(board, j, width-1);
		}
		for(int j =0;j<height; j++){
			for(int i =0;i<width; i++){
				if(board[j][i] == 'O')
					board[j][i] = 'X';
				if(board[j][i] == '#')
					board[j][i] = 'O';
			}
		}
    }

	void show(vector<vector<char> > &board){
		if(board.empty())
			return;

		int height = board.size();
 		int width = board[0].size();

		for(int i = 0; i < height;i++){
			for(int j = 0; j< width;j++){
				cout << board[i][j];
			}
			cout << endl;
		}
	}
};

const int STR_NUM = 4;
int main()
{
	
	string ss[STR_NUM]={
		"XOXOXO",
		"OXOXOX",
		"XOXOXO",
		"OXOXOX",
	};

	{
		Solution_bfs s;
		vector<vector<char> > board;
		for(int i=0;i<STR_NUM;i++)
			board.push_back(vector<char>(ss[i].begin(), ss[i].end()));
		s.solve(board);
		s.show(board);
	}
	cout << endl;
	{
		Solution_dfs s;
		vector<vector<char> > board;
		for(int i=0;i<STR_NUM;i++)
			board.push_back(vector<char>(ss[i].begin(), ss[i].end()));
		s.solve(board);
		s.show(board);
	}
}