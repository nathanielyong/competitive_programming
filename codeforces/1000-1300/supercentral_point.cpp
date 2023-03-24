#include <iostream>
#include <unordered_map>

using namespace std;

pair<int, int> arr[205];
int main() {
    int n, x, y, ans = 0;
    unordered_map<int, pair<int, int>> m_x;
    unordered_map<int, pair<int, int>> m_y;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (m_x.find(x) == m_x.end())
            m_x.insert({x, {y, y}});
        else 
            m_x[x] = {min(m_x[x].first, y), max(m_x[x].second, y)};
        
        if (m_y.find(y) == m_y.end())
            m_y.insert({y, {x, x}});
        else
            m_y[y] = {min(m_y[y].first, x), max(m_y[y].second, x)};

        arr[i] = {x, y};
    }

    for (int i = 0; i < n; ++i) { 
        x = arr[i].first;
        y = arr[i].second;
        if (m_x.find(x) != m_x.end() && m_y.find(y) != m_y.end() && 
            m_x[x].first < y && m_x[x].second > y && m_y[y].first < x && m_y[y].second > x) 
            ++ans;
    }

    cout << ans;

    return 0;
}