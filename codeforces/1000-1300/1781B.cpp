#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t, n, a, ans;
    vector<int> v;
    unordered_map<int, int> m;
    cin >> t;

    while (t--) {
        cin >> n;
        ans = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            m.insert({i, i + 1});
        }

        for (int i = 0; i < n; ++i) {
            if (m[v[i]] && m.find(v[i] + 1) == m.end()) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}