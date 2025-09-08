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

string major(string &s) {
    string t;
    for (int i = 0; i < s.size() / 3; ++i) {
        int n0 = 0, n1 = 0;
        for (int j = 0; j < 3; ++j) {
            if (s[3 * i + j] == '1') ++n1;
            else ++n0;
            t += (n1 > n0 ? "1" : "0");
        }
    }
    return t;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<vector<pair<char, ll>>> a(n, vector<pair<char, ll>>());
    for (int j = 0; j < s.size() / 3; ++j) {
        string sub = s.substr(3 * j, 3);
        if (sub == "000") {
            a[0].emplace_back('0', 2);
        } else if (sub == "001" || sub == "010" || sub == "100") {
            a[0].emplace_back('0', 1);
        } else if (sub == "111") {
            a[0].emplace_back('1', 2);
        } else {
            a[0].emplace_back('1', 1);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < a[i - 1].size() / 3; ++j) {
            vector<int> zero, one;
            for (int k = 0; k < 3; ++k) {
                if (a[i - 1][3 * j  + k].first == '1') {
                    one.push_back(3 * j + k);
                } else {
                    zero.push_back(3 * j + k);
                }
            }
            if (one.size() == 3) {
                ll t1 = a[i-1][one[0]].second;
                ll t2 = a[i-1][one[1]].second;
                ll t3 = a[i-1][one[2]].second;
                a[i].emplace_back('1', t1 + t2 + t3 - max(t1, max(t2, t3)));
            } else if (one.size() == 2) {
                a[i].emplace_back('1', min(a[i-1][one[0]].second, a[i-1][one[1]].second));
            } else if (one.size() == 1) {
                a[i].emplace_back('0', min(a[i-1][zero[0]].second, a[i-1][zero[1]].second));
            } else {
                ll t1 = a[i-1][zero[0]].second;
                ll t2 = a[i-1][zero[1]].second;
                ll t3 = a[i-1][zero[2]].second;
                a[i].emplace_back('0', t1 + t2 + t3 - max(t1, max(t2, t3)));
            }
        }
    }

    cout << a.back()[0].second << endl;

    return 0;
}