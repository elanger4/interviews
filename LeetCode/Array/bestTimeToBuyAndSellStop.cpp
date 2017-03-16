// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Example 1:
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5

// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
// Example 2:
// Input: [7, 6, 4, 3, 1]
// Output: 0

// In this case, no transaction is done, i.e. max profit = 0.
//


#include <algorithm>
#include <iostream>
#include <vector>
#include "assert.h"

int bestTimes(std::vector<int> & stocks) {
    int min = stocks[0];
    int profit = 0;


    if (stocks.size() == 0) {
        return 0;
    }

    for (int i = 1; i < stocks.size(); ++i) {
        if (stocks[i] < min) {
            min = stocks[i];
            continue;
        } else {
            profit = std::max(profit, stocks[i] - min);
        }
    }
    return profit;
}

int main() {

    std::vector<int> example1 {7,1,5,3,6,4};
    std::vector<int> example2 {7,6,4,3,1};

    std::cout << "\nTesting Case 1" << std::endl;
    assert (bestTimes(example1) == 5);
        
    std::cout << "\nTesting Case 2" << std::endl;
    assert (bestTimes(example2) == 0); 

    std::cout << "\nPassed all test cases!\n" << std::endl;
}
