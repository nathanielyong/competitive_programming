#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, a, m, type, l, r;
 
    cin >> n;
    vector<long long> v(n + 1), v2(n + 1);
    vector<long long> dp(n + 1), dp2(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        v[i] = a;
        v2[i] = a;
    }
    sort(v2.begin() + 1, v2.end());
    
    dp[0] = v[0];
    dp2[0] = v2[0];
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + v[i];
        dp2[i] = dp2[i - 1] + v2[i];
    }
 
    cin >> m;
    while(m--) {
        cin >> type >> l >> r;
        if (type == 1) 
            cout << dp[r] - dp[l - 1] << "\n";
        else 
            cout << dp2[r] - dp2[l - 1] << "\n";
    }
    return 0;
}