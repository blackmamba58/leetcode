#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string& s) {
		if (s == "")
			return s;
		string::size_type l(0), r(s.size() - 1);
		while (l < r) {
			swap(s[l++], s[r--]);
		}
		return s;
	}
};