#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int a_i = 0, b_i = 0;
    string res = "";
    while (a_i < (int)a.length() && b_i < (int)b.length()) {
        if (a[a_i] < b[b_i]) 
            res.push_back(a[a_i++]);
        else
            res.push_back(b[b_i++]);
    }
    while (a_i != (int)a.length()) 
        res.push_back(a[a_i++]);
    while (b_i != (int)b.length())
        res.push_back(b[b_i++]);

    cout << res;
}