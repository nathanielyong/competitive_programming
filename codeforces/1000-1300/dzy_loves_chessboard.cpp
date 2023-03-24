#include <iostream>

using namespace std;

int n, m;
char arr[105][105];

void dfs(int i, int j, char c) {
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] != '.') return;
    arr[i][j] = c;
    char new_c = c == 'B' ? 'W' : 'B';

    dfs(i - 1, j, new_c);
    dfs(i, j - 1, new_c);
    dfs(i + 1, j, new_c);
    dfs(i, j + 1, new_c);
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (arr[i][j] == '.') 
                dfs(i, j, 'B');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << arr[i][j];
        cout << "\n";
    }
    return 0;
}

