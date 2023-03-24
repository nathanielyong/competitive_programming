#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    vector<int> v;
    cin >> a >> b >> c;

    int i = 1;
    int y = pow(10, 9);
    int k = pow(i, a);
    int x = k * b + c;
    while (x < y) {
        int sum = 0;
        int rem = x;
        while (rem > 0) {
            sum += rem % 10;
            rem /= 10;
        }
        if (b * pow(sum, a) + c == x) v.push_back(x);
        else if (b * pow((floor(log10(x)) + 1) * 9, a) + c < x) break;
        
        k = pow(++i, a);
        x = k * b + c;
    }

    cout << v.size() << "\n";
    for (int i : v) 
        cout << i << " ";

    return 0;
}