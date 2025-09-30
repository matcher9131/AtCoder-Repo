#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    ll n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

    set<char> charSet;
    for (const char c : s1) charSet.insert(c);
    for (const char c : s2) charSet.insert(c);
    for (const char c : s3) charSet.insert(c);
    if (charSet.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    
    vector<char> p;
    for (const char c : charSet) p.push_back(c);
    while ((ll)p.size() < 10) p.push_back('~');

    do {
        string t1 = s1, t2 = s2, t3 = s3;
        for (ll i = 0; i < n1; ++i) {
            t1[i] = (find(p.begin(), p.end(), s1[i]) - p.begin()) + '0';
        }
        if (t1[0] == '0') continue;
        for (ll i = 0; i < n2; ++i) {
            t2[i] = (find(p.begin(), p.end(), s2[i]) - p.begin()) + '0';
        }
        if (t2[0] == '0') continue;
        for (ll i = 0; i < n3; ++i) {
            t3[i] = (find(p.begin(), p.end(), s3[i]) - p.begin()) + '0';
        }
        if (t3[0] == '0') continue;
        if (stoll(t1) + stoll(t2) == stoll(t3)) {
            cout << t1 << endl;
            cout << t2 << endl;
            cout << t3 << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "UNSOLVABLE" << endl;
    return 0;
}