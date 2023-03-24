#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[30005];
int dp[30005][30005];

int dfs(int i, int l, int sum, int rem) {
    if (i > 30000 || l < 1)
        return 0;
    if (dp[i][l] != -1) 
        return dp[i][l];
    if (l == 1) {
        dp[i][l] = rem;
        return dp[i][l];
    }
    sum += a[i];
    rem -= a[i];
    if (i + l + 1)
    dp[i][l] = max(max(dfs(i + l - 1, l - 1, sum, rem), dfs(i + l, l, sum, rem)), dfs(i + l + 1, l + 1, sum, rem));
    return dp[i][l];
}

int main() {
    int n, d, p;

    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        a[p]++;
    }

    cout << a[0] + dfs(d, d, a[0], n - a[0]);

    return 0;
}