#include "treeStructure.cpp"
#include <vector>

using namespace std;


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums, int startIndex, int endIndex) {
		if (startIndex <= endIndex) {
			int mid = startIndex + (endIndex - startIndex) / 2;
			TreeNode *temp = new TreeNode(nums[mid]);
			temp->left = sortedArrayToBST(nums, startIndex, mid - 1);
			temp->right = sortedArrayToBST(nums, mid + 1, endIndex);
			return temp;
		}
		return NULL;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};