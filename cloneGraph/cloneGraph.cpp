#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *root) {
        queue<UndirectedGraphNode*> q;
		unordered_map<int, UndirectedGraphNode* > m;
		
		if(!root)
			return root;

		UndirectedGraphNode *copy_root = new UndirectedGraphNode(root->label);
		m[root->label] = copy_root;
		q.push(root);

		while(!q.empty()){
			UndirectedGraphNode *n = q.front();
			q.pop();

			UndirectedGraphNode *copy_parent = m[n->label];
			vector<UndirectedGraphNode *>::const_iterator it;
			for(it=n->neighbors.begin();it!=n->neighbors.end();it++){
				int label = (*it)->label;
				if(m.find(label)==m.end()){
					UndirectedGraphNode * copy_node = new UndirectedGraphNode(label);
					m[label] = copy_node;
					copy_parent->neighbors.push_back(copy_node);
					q.push(*it);
				}else{
					copy_parent->neighbors.push_back(m[label]);
				}
			}
		}
		return copy_root;
    }
};

int main()
{
	Solution s;
	s.cloneGraph(NULL);
	return 0;
}