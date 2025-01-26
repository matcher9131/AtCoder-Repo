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
    ll n;
    string s;
    cin >> n >> s;

    ll sum = 0;
    char target = s[0];
    int l = 0;
    while (true) {
        int r = l;
        for (; r < n && s[r] == target; ++r) ;
        ll c = r - l + 1;
        sum += c * (c - 1) / 2;
        if (r >= n) break;
        l = r;
        target = s[r];
    }

    cout << n * (n + 1) / 2 - sum << endl;

    return 0;
}