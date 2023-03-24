#include <iostream>
#include <cmath>

using namespace std;

int a[100005];
int main() {
    int n = 0, m = 0;
    long long sum = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        m = max(m, a[i]);
    }

    int ans = ceil(double(sum) / n - 1);
    cout << (m <= ans ? ans : m);

    return 0;
}