#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		vector<int>::reverse_iterator ri = digits.rbegin();
		while (carry && ri != digits.rend()) {
			*ri += carry;
			carry = *ri / 10;
			*ri++ %= 10;
		}
		if (carry) {
			digits.insert(digits.begin(), carry);
		}
		return digits;
	}
};