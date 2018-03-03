#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int bSize = nums2.size();
		if (bSize == 0)
			return nums2;
		int aSize = nums1.size();
		if (aSize == 0)
			return nums1;
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int a = 0, b = 0; // a is nums1 pointer and b is nums2 pointer
		while (b < bSize && a < aSize) {
			if (nums1[a] > nums2[b]) {
				b++;
			}
			else if (nums1[a] < nums2[b]) {
				a++;
			}
			else {
				result.push_back(nums1[a++]);
				b++;
			}
		}
		return result;
	}
};