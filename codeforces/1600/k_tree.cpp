#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, k, d;
    long long dp[105];
    cin >> n >> k >> d;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        if (i <= k)
            dp[i] = 1;
        for (int j = 1; j <= k && i - j >= 1; ++j) 
            dp[i] += dp[i - j]; 
        for (int j = 1; j < d && i - j >= 1; ++j) 
            dp[i] -= dp[j];
        for (int j = d; j <= k && i - j >= 1; ++j)
            dp[i] += dp[i - j] + dp[j];
        dp[i] %= 1000000007;
    }    
    for (int i = 1; i < d && n - i >= 1; ++i) 
        dp[n] -= dp[i];

    for (int i = 1; i <= n; ++i) 
        cout << dp[i] << " ";
    cout << "\n";
    cout << dp[n];

    return 0;
}