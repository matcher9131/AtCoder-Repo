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

void display(const vector<int>& v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main() {
    int n;
    string t0;
    cin >> n >> t0;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i].size() == t0.size()) {
            int err = 0;
            for (int j = 0; j < t0.size(); ++j) {
                if (s[i][j] != t0[j]) ++err;
            }
            if (err <= 1) ans.push_back(i + 1);
        } else if (s[i].size() == t0.size() + 1 || s[i].size() == t0.size() - 1) {
            string shorter = s[i].size() < t0.size() ? s[i] : t0;
            string longer = s[i].size() > t0.size() ? s[i] : t0;

            int l = 0, r = 0;
            for (int j = 0; j < min(s[i].size(), t0.size()); ++j) {
                if (s[i][j] != t0[j]) break;
                ++l;
            }
            if (longer.ends_with(shorter.substr(l))) ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    display(ans);

    return 0;
}