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
    int n, k;
    string s;
    cin >> n >> k >> s;
    --k;

    // [l, r)
    vector<pair<int, int>> ones;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int l = i;
            while (i < n && s[i] == '1') ++i;
            ones.emplace_back(l, i);
        }
    }

    auto [lb, rb] = ones[k - 1];
    auto [l, r] = ones[k];
    int i = rb;
    for (; i < rb + r - l; ++i) {
        s[i] = '1';
    }
    for (; i < r; ++i) {
        s[i] = '0';
    }

    cout << s << endl;

    return 0;
}