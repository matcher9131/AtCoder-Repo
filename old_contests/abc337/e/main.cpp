#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;

    int m = bit_width((unsigned)(n-1));
    cout << m << endl;

    vector<vector<int>> a(m);
    for (int bit = 0; bit < n; ++bit) {
        for (int i = 0; i < m; ++i) {
            if (bit & (1 << i)) a[i].push_back(bit);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << a[i].size() << " ";
        for (int j = 0; j < (int)a[i].size(); ++j) {
            cout << a[i][j]+1 << " \n"[j == (int)a[i].size() - 1];
        }
    }

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (s[i] == '1') ans |= 1 << i;
    }

    cout << ans+1 << endl;
    return 0;
}