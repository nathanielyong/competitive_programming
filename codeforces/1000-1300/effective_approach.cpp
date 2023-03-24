#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, m, b;
    unordered_map<int, int> u;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        u.insert({a, i});
    }
    
    cin >> m;
    int v = 0, p = 0; 
    for (int i = 0; i < m; ++i) {
        cin >> b;
        v += u[b] + 1;
        p += n - u[b];
    }
    cout << v << " " << p;

    return 0;
}