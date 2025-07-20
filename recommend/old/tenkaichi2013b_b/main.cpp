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
using namespace std;
using ll = long long;


int main() {
    int nq, l;
    cin >> nq >> l;
    vector<tuple<string, ll, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        string s;
        int n = -1, m = -1;
        cin >> s;
        if (s == "Push") {
            cin >> n >> m;
        } else if (s == "Pop") {
            cin >> n;
        }
        q[i] = make_tuple(s, n, m);
    }

    // value, count
    stack<pair<int, ll>> s;
    ll size = 0;
    for (int i = 0; i < nq; ++i) {
        auto [order, n, m] = q[i];
        if (order == "Push") {
            if (size + n > l) {
                cout << "FULL" << endl;
                return 0;
            }
            s.emplace(m, n);
            size += n;
        } else if (order == "Pop") {
            while (n > 0) {
                if (s.empty()) {
                    cout << "EMPTY"<< endl;
                    return 0;
                }
                auto [tm, tn] = s.top();
                s.pop();
                ll d = min(n, tn);
                tn -= d;
                n -= d;
                size -= d;
                if (tn > 0) s.emplace(tm, tn);
            }
        } else if (order == "Top") {
            if (s.empty()) {
                cout << "EMPTY"<< endl;
                return 0;
            }
            auto [tm, tn] = s.top();
            cout << tm << endl;
        } else if (order == "Size") {
            cout << size << endl;
        }
    }

    cout << "SAFE" << endl;

    return 0;
}