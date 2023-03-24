#include <iostream>
#include <algorithm>

using namespace std;

int arr[500005];
int main() {
    int n, sum = 0, maxx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        maxx = max(maxx, arr[i]);
    }
    sort(arr, arr + n);

    if (maxx > sum / 2) 
        cout << 1;
    else {    
        for (int i = 0; i < n; ++i) {
            if (maxx > (sum - arr[i]) / 2) {
                cout << n - i;
                break;
            }
            sum -= arr[i];
        }
    }
    return 0;
}