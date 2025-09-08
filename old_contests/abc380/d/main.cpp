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
using ull = unsigned long long;
#include <bitset>

char transform(char c) {
    if ('a' <= c && c <= 'z') {
        return 'A' + c - 'a';
    } else {
        return 'a' + c - 'A';
    }
}

bool getChanges(ull k, bool inv) {
    if (k == 0) return inv;
    return getChanges(k % bit_floor(k), !inv);
}

int main() {
    string s;
    int nq;
    cin >> s >> nq;
    ull l = s.size();
    for (int i = 0; i < nq; ++i) {
        ull k;
        cin >> k;
        --k;
        ull q = k / l, r = k % l;
        cout << (getChanges(q, false) ? transform(s[r]) : s[r]) << " \n"[i == nq - 1];
    }

    return 0;
}