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

bool containsZero(ll n) {
    string s = to_string(n);
    for (const char c : s) {
        if (c == '0') return true;
    }
    return false;
}

ll reversedNumber(ll n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stol(s);
}

bool isPalindromic(ll n) {
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

string search(ll n) {
    if (!containsZero(n) && isPalindromic(n)) {
        return to_string(n);
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (containsZero(i)) continue;
        if (n % i == 0) {
            ll r = reversedNumber(i);
            if (n / i % r == 0) {
                string result = search(n / i / r);
                if (result != "") return to_string(i) + "*" + result + "*" + to_string(r);
            }
        }
    }
    return "";
}

int main() {
    ll n;
    cin >> n;

    string ans = search(n);

    cout << (ans == "" ? "-1" : ans) << endl;

    return 0;
}