#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[7];
    cin >> n;
    int sum = 0, day = 0;

    for (int i = 0; i < 7; ++i) 
        cin >> arr[i];

    while (sum < n) {
        sum += arr[day];
        day = ++day % 7;
    }
    
    cout << (day == 0 ? 7 : day);

    return 0;
}