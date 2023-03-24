#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        vector<int> v;

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> k;
            a[i] = k;
            if (b[k] >= 1) 
                v.push_back(i);
            else {
                ++b[k];
                ++ans;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0) {
                int k = v.back();
                if (k == i) {
                    if (v.size() == 1) {
                        for (int j = 1; j < n; ++j) 
                            if (a[j] == a[i]) {
                                a[i] = a[j];
                                a[j] = i;
                                v.pop_back();
                                break;
                            }
                    } else {
                        v.pop_back();
                        a[v.back()] = i;
                        v.pop_back();
                        v.push_back(k);
                    }
                } else {
                    a[k] = i;
                    v.pop_back();
                }
            } 
            if (v.empty())
                break;
        }

        cout << ans << "\n";
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " ";
    }

    return 0;
}