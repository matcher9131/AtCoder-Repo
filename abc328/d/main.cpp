#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    list<char> t;
    for (ll i = 0; i < n; ++i) {
        t.push_back(s[i]);
    }

    auto it = t.begin();
    while (it != t.end()) {
        if (*it == 'A') {
            auto it2 = it;
            ++it2;
            if (it2 != t.end() && *it2 == 'B') {
                auto it3 = it2;
                ++it3;
                if (it3 != t.end() && *it3 == 'C') {
                    t.erase(it3);
                    t.erase(it2);
                    it = t.erase(it);
                    if (it != t.begin()) --it;
                    if (it != t.begin()) --it;
                    continue;
                }
            }
        }
        ++it;
    }

    for (auto it = t.begin(); it != t.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    return 0;
}