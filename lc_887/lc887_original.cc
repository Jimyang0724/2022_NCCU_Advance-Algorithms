#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        // init table for record
        vector<vector<int>> table(K+1, vector<int>(N+1, INT_MAX));

        // recursion (lambda expression)
        function<int(int, int)> dp = [&](int k, int n) {
            // base case
            if(k == 0) return 0;
            else if(k == 1) return n;
            else if(n <= 1) return n;

        };

        return dp(K, N);
    }
};

int main() {
    Solution s;
    s.superEggDrop(1, 2);
    return 0;
}