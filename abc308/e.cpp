#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using int64 = long long;

int mex(int a, int b, int c) {
    int d[4] = { 0, 0, 0, 0 };
    d[a] = 1;
    d[b] = 1;
    d[c] = 1;
    for (int i = 0; i < 4; ++i) {
        if (d[i] == 0) return i;
    }
    return 3;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;

    vector<vector<int>> lm(3, vector<int>(n));
    vector<vector<int>> rx(3, vector<int>(n));
    vector<int> lmc(3);
    vector<int> rxc(3);
    for (int i = 0; i < n; ++i) {
        int ac = a[i];
        if (s[i] == 'M') {
            ++lmc[ac];
        } else if (s[i] == 'X') {
            ++rxc[ac];
        }
        for (int x = 0; x < 3; ++x) {
            lm[x][i] = lmc[x];
            rx[x][i] = rxc[x];
        }
    }

    int64 c = 0;
    for (int j = 1; j < n - 1; ++j) {
        if (s[j] != 'E') continue;
        for (int p = 0; p < 3; ++p) {
            for (int q = 0; q < 3; ++q) {
                c += (int64)lm[p][j] * (rx[q][n - 1] - rx[q][j]) * mex(p, a[j], q);
            }
        }
    }
    
    cout << c << endl;

    return 0;
}