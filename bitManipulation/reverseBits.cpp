#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		bitset<32> xBS(n);
		int left(0), right(31);
		while (left < right) {
			if (xBS[left] != xBS[right]) {
				xBS[left].flip();
				xBS[right].flip();
			}
			left++; right--;
		}
		return (unsigned int)xBS.to_ulong();
	}
};

int main() {
	Solution sol;
	cout << sol.reverseBits(43261596);
	getchar();
	return 0;
}