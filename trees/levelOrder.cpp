#include "treeStructure.cpp"
#include <vector>

using namespace std;

class Solution {
public:
	void levelOrder(TreeNode* root, int currentLevel, vector<vector<int>>& sol) {
		if (root == NULL)
			return;
		if (sol.size() == currentLevel) {
			sol.push_back(vector<int>());
		}
		sol[currentLevel].push_back(root->val);
		levelOrder(root->left, currentLevel + 1, sol);
		levelOrder(root->right, currentLevel + 1, sol);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> sol;
		levelOrder(root, 0, sol);
		return sol;
	}
};