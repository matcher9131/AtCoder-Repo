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
#include <bitset>
using namespace std;
using ll = long long;

constexpr int BIT_MAX = 16;
constexpr int MAX = 1 << BIT_MAX;

int countBits(int n) {
    int count = 0;
    for (int i = 0; i < BIT_MAX; ++i) {
        if (n & 1 << i) ++count;
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Bonus, Combination(bit)
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; ++i) {
        int bonus, num;
        cin >> bonus >> num;
        int comb = 0;
        for (int j = 0; j < num; ++j) {
            int t;
            cin >> t;
            --t;
            comb |= 1 << t;
        }
        b[i] = make_pair(bonus, comb);
    }

    int maxValue = 0;
    int bitMax = 1 << n + 1;
    for (int bit = 0; bit < bitMax; ++bit) {
        if (countBits(bit) != 9) continue;
        int value = 0;
        for (int ii = 0; ii < n; ++ii) {
            if (bit & 1 << ii) value += a[ii];
        }
        for (int bi = 0; bi < m; ++bi) {
            auto [bonus, comb] = b[bi];
            if (countBits(bit & comb) >= 3) value += bonus;
        }
        maxValue = max(maxValue, value);
    }

    cout << maxValue << endl;

    return 0;
}