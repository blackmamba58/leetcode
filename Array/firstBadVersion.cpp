#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int start, int end) {
		if (start == end) {
			return start;
		}
		int mid = start + (end - start) / 2;
		if (isBadVersion(mid)) {
			return firstBadVersion(start, mid);
		}
		return firstBadVersion(mid + 1, end);
	}
	int firstBadVersion(int n) {
		return firstBadVersion(1, n);
	}
};