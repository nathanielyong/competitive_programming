#include <iostream>

using namespace std;

int arr[100005];
int main() {
    int n;
    cin >> n;

    arr[0] = INT_MAX;
    arr[n + 1] = INT_MIN;
    for (int i = 1; i <= n; ++i) 
        cin >> arr[i];
    
    int ans = 1, cnt = 0, i = 0, j = 1, prev = 0;
    while (i <= n) {
        for (int k = i; k <= j; ++k) 
            cout << arr[k] << " ";
        cout << "\n";
        
        if (cnt == 2) {
            while (i <= prev) 
                ++i;
            prev = i;
        }
        if (arr[j - 1] >= arr[j]) 
            ++cnt;
        else if (arr[prev] >= arr[j]) 
            ++cnt;

        ans = max(ans, j - i);
        j == n + 1 ? ++i : ++j;
    }
    cout << ans;

    return 0;
}