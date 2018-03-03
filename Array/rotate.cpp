#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// reverse method. write juggling algorithm for same
	void rotate(vector<int>& nums, int k) {
		if (k == 0)
			return;
		if (k > nums.size())
			k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};