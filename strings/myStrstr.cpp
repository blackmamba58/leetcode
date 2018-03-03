#include <string>

using namespace std;

class Solution {
public:
	int needleSize;

	bool compare(string &haystack, int startIndex, string &needle) {
		int needleIndex(1);
		while (needleIndex < needleSize) {
			if (haystack[startIndex++] != needle[needleIndex++])
				return false;
		}
		return true;
	}

	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		needleSize = needle.size();
		int diff = haystack.size() - needleSize + 1;
		for (int i = 0; i < diff; ++i) {
			if (haystack[i] == needle[0]) {
				if (compare(haystack, i + 1, needle)) {
					return i;
				}
			}
		}
		return -1;
	}
};