#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();

    vector<ll> sch(27);
    vector<ll> tch(27);
    for (ll i = 0; i < n; ++i) {
        ++sch[s[i] == '@' ? 26 : s[i] - 'a'];
        ++tch[t[i] == '@' ? 26 : t[i] - 'a'];
    }

    ll sSum = 0, tSum = 0;
    for (ll i = 0; i < 26; ++i) {
        switch (i) {
            case 0:
            case 19:
            case 2:
            case 14:
            case 3:
            case 4:
            case 17:
                if (sch[i] > tch[i]) tSum += sch[i] - tch[i];
                else sSum += tch[i] - sch[i];
                break;
            default:
                if (sch[i] != tch[i]) {
                    cout << "No" << endl;
                    return 0;
                }
                break;
        }
    }

    cout << (sch[26] >= sSum && tch[26] >= tSum ? "Yes" : "No") << endl;

    

    return 0;
}