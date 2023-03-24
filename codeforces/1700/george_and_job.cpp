#include <iostream>
#include <cstring>

using namespace std;

long long arr[5005];
long long sums[5005];
long long dp[5005][5005];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(sums, 0, n * sizeof(int));
    memset(dp, 0, n * (k + 1) * sizeof(int));

    for (int i = 0; i < n; ++i) 
        cin >> arr[i];

    for (int i = 0; i < m; ++i) 
        sums[0] += arr[i];
    
    for (int i = 1; i < n - m + 1; ++i) 
        sums[i] = sums[i - 1] - arr[i - 1] + arr[i + m - 1];

    for (int i = 0; i < n - m + 1; ++i) 
        dp[i][1] = sums[i];

    for (int i = 1; i < n - m + 1; ++i) 
        for (int j = 0; j < i - m + 1; ++j) 
            for (int count = 2; count <= k; ++count)
                dp[i][count] = max(dp[i][count], dp[i][1] + dp[j][count - 1]);

    long long ans = 0;
    for (int i = 0; i < n - m + 1; ++i)
        ans = max(ans, dp[i][k]);

    cout << ans;

    return 0;
}