#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int start, end, currSum, result, minimumDifference = INT_MAX;
		for (int i = 0, size = nums.size(); i < size; ++i) {
			if (i) { // i != 0
				while (nums[i] == nums[i - 1]) i++;
			}
			start = i + 1;
			end = size - 1;
			while (start < end) {
				currSum = nums[i] + nums[start] + nums[end];
				cout << currSum << "\t" << minimumDifference << "\n";
				if (minimumDifference > abs(target - currSum)) {
					minimumDifference = abs(target - currSum);
					result = currSum;
				}
				if (currSum > target) {
					end--;
				}
				else if (currSum < target) {
					start++;
				}
				else {
					return target;
				}
			}
		}
		return result;
	}
};