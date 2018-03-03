#include "treeStructure.cpp"

class Solution {
public:
	bool isValidBSTHelper(TreeNode *root, TreeNode **pre) {
		if (root == NULL)
			return true;
		if (isValidBSTHelper(root->left, pre)) {
			if (*pre && (*pre)->val >= root->val)
				return false;
			*pre = root;
			return isValidBSTHelper(root->right, pre);
		}
		return false;
	}
	bool isValidBST(TreeNode* root) {
		TreeNode *temp = NULL;
		return isValidBSTHelper(root, &temp);
	}
};