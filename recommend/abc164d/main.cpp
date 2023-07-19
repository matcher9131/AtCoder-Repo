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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;
    int n = s.size();

    ll count = 0;
    // 以下添え字は0-indexed
    // S[i, N)を10進数と見たときのmod 2019をf(i)とするとき、
    // r[j] = (f(i) == j)となるiの個数とおく
    // ※ただしf(N) = 0とする
    // i < jのとき、f(i) == f(j)ならばS[i, N)は条件を満たす
    vector<ll> r(2020);
    r[0] = 1;
    int rc = 0;
    int r10 = 1;
    for (int i = n - 1; i >= 0; --i) {
        rc = (rc + r10 * (s[i] - '0')) % 2019;
        count += r[rc];
        ++r[rc];
        r10 = 10 * r10 % 2019;
    }

    cout << count << endl;

    return 0;
}