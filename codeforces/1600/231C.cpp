#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    sort(a, a + n);

    int i = 0, j = 1, ans = 1, ans2 = 0;
    for (int i = 0; i < n; ++i) 
        cout << a[i] << " ";
    while (i < n) {
        if (a[j] - a[i] <= k) {
            if (ans < j - i + 1) {
                ans = j - i + 1;
                ans2 = j;
            }
            j < n - 1 ? ++j : ++i;
        } else 
            ++i;
    }
    cout << ans << " " << a[ans2];

    return 0;
}