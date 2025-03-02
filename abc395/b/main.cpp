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
    vector<string> s(n, string(n, '.'));

    for (int i = 0; i < (n + 1) / 2; ++i) {
        if (i % 2) continue;
        for (int x = i; x < n - i; ++x) {
            s[i][x] = '#';
            s[n - i - 1][x] = '#';
            s[x][i] = '#';
            s[x][n - i - 1] = '#';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }

    return 0;
}