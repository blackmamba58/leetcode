#include "treeStructure.cpp"

class Solution {
public:
	bool isSymmetric(TreeNode *left, TreeNode *right) {
		if (left && right) {
			return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		}
		else if (left == NULL && right == NULL) {
			return true;
		}
		return false;
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
	}
};