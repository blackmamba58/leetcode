#include <string>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int size = s.size();
		if (size != t.size())
			return false;
		int arr[26] = { 0 };
		for (int i = 0; i < size; ++i) {
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i < size; ++i) {
			arr[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; ++i) {
			if (arr[i])
				return false;
		}
		return true;
	}
};