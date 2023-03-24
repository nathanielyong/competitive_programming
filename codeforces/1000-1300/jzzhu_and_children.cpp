#include <iostream>
#include <queue>

using namespace std;

int arr[105];
int main()
{
    int n, m; 
    queue<int> q;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i + 1];
        q.push(i + 1);
    }
    
    while (!q.empty()) { 
        if (q.size() == 1) {
            cout << q.front();
        } else if (arr[q.front()] > m) {
            q.push(q.front());
            arr[q.front()] -= m;
        } else
            arr[q.front()] = 0;
        
        q.pop();
    }

    return 0;
}