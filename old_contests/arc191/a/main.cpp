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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<pair<char, int>> tt(m);
    for (int i = 0; i < m; ++i) {
        tt[i] = make_pair(t[i], i);
    }
    sort(tt.begin(), tt.end(), greater<pair<char, int>>());
    bool lastUsed = false;

    int j = 0;
    for (int i = 0; i < n && j < m; ++i) {
        if (s[i] < tt[j].first) {
            s[i] = tt[j].first;
            if (tt[j].second == m - 1) {
                lastUsed = true;
            }
            ++j;
        }
    }

    // t[m-1]が使われない場合、同じ数字がsになければ1の位と入れ替える
    if (!lastUsed && s.find(t[m - 1]) == string::npos) {
        s[n - 1] = t[m - 1];
    }

    cout << s << endl;

    return 0;
}