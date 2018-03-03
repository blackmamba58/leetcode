#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMinima(vector<int>& prices, int& startIndex, int endIndex) {
		if (startIndex > endIndex)
			return 0;
		if (startIndex == endIndex)
			return prices[startIndex];
		while (startIndex < endIndex && prices[startIndex] > prices[startIndex + 1]) {
			startIndex++;
		}
		return prices[startIndex];
	}
	int getMaxima(vector<int>& prices, int& startIndex, int endIndex) {
		if (startIndex > endIndex)
			return 0;
		if (startIndex == endIndex)
			return prices[startIndex];
		while (startIndex < endIndex && prices[startIndex] < prices[startIndex + 1]) {
			startIndex++;
		}
		return prices[startIndex];
	}

	int maxProfit(vector<int>& prices) {
		int purchasePrice, currPrice, sellPrice, profit = 0;
		for (int i = 0, size = prices.size(); i < size; ++i) {
			purchasePrice = getMinima(prices, i, size - 1);
			sellPrice = getMaxima(prices, i, size - 1);
			if (sellPrice > purchasePrice)
				profit += sellPrice - purchasePrice;
		}
		return profit;
	}
};

class editorialSolution {
public:
	// editorial solution 2.. trick was to use endIndex instead of size
	int maxProfit(vector<int>& prices) {
		int valley(0), peak(0), profit(0), i(0), endIndex(prices.size() - 1);
		while (i < endIndex) {
			while (i < endIndex && prices[i] >= prices[i + 1])
				i++;
			valley = prices[i];
			while (i < endIndex && prices[i] <= prices[i + 1])
				i++;
			peak = prices[i];
			profit += peak - valley;
		}
		return profit;
	}
};

class Driver {
public:
	void run() {
		Solution sol;
		vector<int> v = { 1,4,2,8,6,9 };
		//sort(v.begin(), v.end());
		//reverse(v.begin(), v.end());
		cout << sol.maxProfit(v);
	}
};

//int main() {
//	Driver d;
//	d.run();
//	getchar();
//	return 0;
//}