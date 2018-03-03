#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int start, end, sum;
		for (int i = 0, size = nums.size(); i < size - 3; ++i) {
			if (i) {
				while (nums[i] == nums[i - 1]) i++;
			}
			for (int j = i + 1; j < size - 2; ++j) {
				if (j != i + 1) {
					while (nums[j] == nums[j - 1]) j++;
				}
				start = j + 1;
				end = size - 1;
				while (start < end) {
					sum = nums[i] + nums[j] + nums[start] + nums[end];
					if (sum < target) start++;
					else if (sum > target) end--;
					else {
						result.push_back({ nums[i], nums[j], nums[start], nums[end] });
						// here we need to decide what to do with start and end
						start++;
						while (start != end && nums[start] == nums[start - 1]) start++;
					}
				}
			}
		}
		return result;
	}
};

class Driver {
public:
	void run() {
		Solution sol;
		vector<int> v = { 1,0,-1,0,-2,2,7,3,8,2,9,7,-8,5,0,9,8,2,3,7 };
		//sort(v.begin(), v.end());
		//reverse(v.begin(), v.end());
		vector<vector<int>> res = sol.fourSum(v, 5);
	}
};

int main() {
	Driver d;
	d.run();
	getchar();
	return 0;
}