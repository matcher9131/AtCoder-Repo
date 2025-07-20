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

bool isPalindrome(const string_view &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

void solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;

    k %= 2 * n;
    
    string t(k, ' ');
    for (int i = 0; i < min(k, n); ++i) {
        t[k-1-i] = s[i];
        t[min(k,n)-1-i] = s[i];
    }
    cout << (isPalindrome(s + t) && isPalindrome(t + s) ? "Yes" : "No") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}