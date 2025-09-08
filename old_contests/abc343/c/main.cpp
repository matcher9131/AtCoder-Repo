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

bool isPalindrome(string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;

    string ans = "";
    for (ll i = 1; i * i * i <= n; ++i) {
        string s = to_string(i * i * i);
        if (isPalindrome(s)) {
            ans = s;
        }
    }

    cout << ans << endl;

    return 0;
}