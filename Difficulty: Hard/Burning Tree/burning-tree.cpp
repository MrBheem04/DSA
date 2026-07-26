/*
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};
*/

class Solution {
	public:
	int minTime(Node* root, int target) {
		// code here
		unordered_map<int, vector<int>> graph;
		bulidGraph(root, nullptr, graph);
		
		unordered_set<int>visited;
		
		queue<int>q;
		q.push(target);
		visited.insert(target);
		
		int time = 0;
		
		while (!q.empty()) {
			int size = q.size();
			bool burned = false;
			
			for (int i = 0; i<size; i++) {
				int node = q.front();
				q.pop();
				
				for (int neighbours : graph[node]) {
					if (visited.count(neighbours) == 0) {
						visited.insert(neighbours);
						q.push(neighbours);
						burned = true;
					}
				}
			}
			if (burned)time++;
		}
		return time;
	}
	private:
	void bulidGraph(Node* node, Node* parent, unordered_map<int, vector<int>> &graph) {
		if (!node)return;
		
		if (parent) {
			graph[node->data].push_back(parent->data);
			graph[parent->data].push_back(node->data);
			
		}
		bulidGraph(node->left, node, graph);
		bulidGraph(node->right, node, graph);
	}
};
