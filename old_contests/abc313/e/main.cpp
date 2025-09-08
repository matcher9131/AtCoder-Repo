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
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int oneStart = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1') {
            if (oneStart > 0 && oneStart == i) {
                cout << -1 << endl;
                return 0;
            }
            v.emplace_back(i - oneStart, (int)(s[i] - '0'));
            oneStart = i + 1; 
        }
    }
    if (oneStart < n) {
        v.emplace_back(n - oneStart, 0);
    }

    ll answer = 0;
    while (!v.empty()) {
        auto [numOne, notOne] = v.back();
        v.pop_back();
        if (numOne == 0) {
            ++answer;
            answer %= MOD;
        } else {
            answer += answer * (notOne - 1) % MOD;
            answer %= MOD;
            answer += numOne + notOne;
            answer %= MOD;
        }
    }

    cout << answer - 1 << endl;

    return 0;
}