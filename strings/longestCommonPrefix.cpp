#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size == 0)
			return "";
		if (size == 1)
			return strs[0];
		int lengthOfString = strs[0].size();
		string result;
		for (int i = 0; i < lengthOfString; ++i) {
			char temp = strs[0][i];
			for (int j = 1; j < size; j++) {
				if (i >= strs[j].size() || temp != strs[j][i])
					return result;
			}
			result.push_back(temp);
		}
		return result;
	}
};