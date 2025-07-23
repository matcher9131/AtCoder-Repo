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
#include <atcoder/modint>
using namespace std;
using ll = long long;
constexpr ll INF = 1e16;
using mint = atcoder::modint1000000007;

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    mint base3 = 3;
    mint base2 = 2;
    int countOne = 0;
    mint ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans += base2.pow(countOne) * base3.pow(n-1-i);
            ++countOne;
        }
    }
    ans += base2.pow(countOne);

    cout << ans.val() << endl;
    return 0;
}