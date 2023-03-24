#include <iostream>

using namespace std;

int main() {
    int n, m, a;
    int arr[1005];
    int ans[105];
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
        cin >> arr[i];
    
    for (int i = 1; i <= n; ++i) {
        a = i;
        for (int j = 0; j < m; ++j) {
            if (arr[j] == a) 
                a++;
            else if (arr[j] == a - 1)
                a--;
        }
        ans[a] = i;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";

    return 0;
}