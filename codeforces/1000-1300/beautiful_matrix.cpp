#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> n;
            if (n) cout << abs(i - 2) + abs(j - 2) << "\n";
        }
    }
    
    return 0;
}