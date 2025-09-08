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
    int k;
    string s, t;
    cin >> k >> s >> t;

    if (s == t) {
        cout << "Yes" << endl;
    } else if (s.length() == t.length() + 1) {
        int l = 0;
        for (int i = 0; i < t.length(); ++i) {
            if (s[i] == t[i]) {
                ++l;
            } else {
                break;
            }
        }
        if (s.substr(l + 1) == t.substr(l)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (t.length() == s.length() + 1) {
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[i]) {
                ++l;
            } else {
                break;
            }
        }
        if (s.substr(l) == t.substr(l + 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (s.length() == t.length()) {
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[i]) {
                ++l;
            } else {
                break;
            }
        }
        if (s.substr(l + 1) == t.substr(l + 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}