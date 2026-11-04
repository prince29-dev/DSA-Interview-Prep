class Solution {
public:
    multiset<int> left, right;

    long long sumLeft = 0, sumRight = 0;

    // Balance two multisets
    void balance() {

        while (left.size() > right.size() + 1) {

            int val = *left.rbegin();

            left.erase(left.find(val));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (left.size() < right.size()) {

            int val = *right.begin();

            right.erase(right.find(val));
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    // Insert element
    void add(int num) {

        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
            sumLeft += num;
        }
        else {
            right.insert(num);
            sumRight += num;
        }

        balance();
    }

    // Remove element
    void remove(int num) {

        auto it = left.find(num);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= num;
        }
        else {
            auto itr = right.find(num);
            right.erase(itr);
            sumRight -= num;
        }

        balance();
    }

    // Calculate minimum operations
    long long getCost() {

        long long median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        vector<long long> cost;

        // First window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        // Sliding Window
        for (int i = x; i < n; i++) {

            remove(nums[i - x]);

            add(nums[i]);

            cost.push_back(getCost());
        }

        // DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= k; j++) {

                // Option 1: Skip current element
                dp[i][j] = dp[i - 1][j];

                // Option 2: Select a window of size x
                if (j > 0 && i >= x &&
                    dp[i - x][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};