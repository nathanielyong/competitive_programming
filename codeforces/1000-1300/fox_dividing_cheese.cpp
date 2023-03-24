#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) 
    return a;
  return gcd(b, a % b);
}

int main() {
    int a, b;
    int arr[3] = {5, 3, 2};
    cin >> a >> b;

    int d = gcd(a, b);
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        while (a / d % arr[i] == 0 && a != d) {
            a /= arr[i];
            ++ans;
        }
        while (b / d % arr[i] == 0 && b != d) {
            b /= arr[i];
            ++ans;
        }
    }   

    cout << (a == b && a == d ? ans : -1);

    return 0;
}