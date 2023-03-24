#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, x, y, z;
    int a[3];
    memset(a, 0, sizeof(a));
    cin >> n;

    while (n--) {
        cin >> x >> y >> z;
        a[0] += x;
        a[1] += y;
        a[2] += z;
    }
    if (a[0] || a[1] || a[2]) 
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}