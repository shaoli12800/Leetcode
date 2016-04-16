// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>


using namespace std;

//Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class CloneGraph_133_Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL){
			return NULL;
		}
		queue<UndirectedGraphNode*> Q;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copyNode;
		Q.push(node);

		while (!Q.empty()){
			UndirectedGraphNode *temp = Q.front();
			if (copyNode.find(temp) == copyNode.end()){
				UndirectedGraphNode *copy = new UndirectedGraphNode(temp->label);
				copyNode.insert(make_pair(temp, copy));
			}
			//copy node
			for (int i = 0; i<temp->neighbors.size(); i++){
				if (copyNode.find(temp->neighbors[i]) == copyNode.end()){
					UndirectedGraphNode *copy = new UndirectedGraphNode(temp->neighbors[i]->label);
					copyNode.insert(make_pair(temp->neighbors[i], copy));
					Q.push(temp->neighbors[i]);
				}
			}
			//copy connection
			for (int i = 0; i<temp->neighbors.size(); i++){
				copyNode.find(temp)->second->neighbors.push_back(copyNode.find(temp->neighbors[i])->second);
			}

			Q.pop();
		}
		return copyNode.find(node)->second;
	}
};






int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

