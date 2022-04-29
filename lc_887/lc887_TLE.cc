#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

class Solution {
// # of subproblems O(KN), complexity of each take O(N)
// Time complexity O(KN^2)
// Space complexity O(KN)
public:
    int superEggDrop(int K, int N) {
        // Init table for record
        vector<vector<int>> table(K+1, vector<int>(N+1, INT_MAX));

        // Recursion (lambda expression)
        function<int(int, int)> dp = [&](int k, int n) {
            // Base case
            if(k == 0) return 0;
            else if(k == 1) return n;
            else if(n <= 1) return n;
            
            int& ans = table[k][n];
            if(ans != INT_MAX) return ans;  // dp(k, n) has done
            for(int i=1; i<=n; i++) {   // Drop from i floor
                // Broken   => dp(k-1, i-1), has k-1 eggs and i-1 floors to check
                // Unbroken => dp(k,   n-i), has k eggs and n-i floors to check
                // max      => select worst case of check
                // min      => select floor with minimum cost to drop
                ans = min(ans, 1 + max(dp(k-1, i-1), dp(k, n-i)));
            }
            return ans;
        };

        return dp(K, N);
    }
};

int main() {
    Solution s;
    int K, N;
    cout << "K: ";
    cin >> K;
    cout << "N: ";
    cin >> N;
    cout << s.superEggDrop(K, N) << endl;
    return 0;
}