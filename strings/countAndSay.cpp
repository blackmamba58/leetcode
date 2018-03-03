/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(string& s) {
		string result;
		int count = 1;
		for (int i = 0, size = s.size(); i < size; ++i) {
			while (i + 1 < size && s[i] == s[i + 1]) {
				count++;
				i++;
			}
			result += to_string(count) + s[i];
			count = 1;
		}
		return result;
	}
	string countAndSay(int n) {
		string result = "1";
		for (int i = 1; i < n; ++i) {
			result = countAndSay(result);
		}
		return result;
	}
};

class Driver {
public:
	void run() {
		Solution sol;
		string s = "111221";
		cout << sol.countAndSay(s);
	}
};

//int main() {
//	Driver d;
//	d.run();
//	getchar();
//	return 0;
//}