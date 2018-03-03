#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string &str) {
		int i(0), size(str.size()); //iterator

		// check for leading space
		while (i < size && str[i++] == ' ');
		i--;


		//check for positive or negative sign
		bool negativeNumber = false;
		if (str[i] == '-') {
			negativeNumber = true;
			i++;
		}
		else if (str[i] == '+') {
			i++;
		}

		long long int result(0);
		while (i < size && isdigit(str[i])) {
			result = result * 10 + str[i++] - '0';
			if (result > INT_MAX)
				break;
		}
		
		if (negativeNumber)
			result *= -1;

		if (result > INT_MAX)
			return INT_MAX;

		if (result < INT_MIN)
			return INT_MIN;

		return result;
	}
};