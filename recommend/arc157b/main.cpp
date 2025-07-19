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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll numX = count(s.begin(), s.end(), 'X');
    bool invert = k > numX;
    if (invert) k = n-k;
    // 'Y'がない
    char cy = invert ? 'X' : 'Y';
    if (count(s.begin(), s.end(), cy) == 0) {
        cout << max(k-1, 0LL) << endl;
        return 0;
    }
    
    ll ans = 0;
    // Yに挟まれたXの長さ
    vector<ll> xSeg;
    ll xLeft = -1, yLeft = -1;
    for (ll i = 0; i < n; ++i) {
        if ((s[i] == 'X') ^ invert) {
            if (xLeft == -1) {
                xLeft = i;
            }
            if (yLeft != -1) {
                ans += i - yLeft - 1;
                yLeft = -1;
            }
        } else {
            if (xLeft != -1) {
                if (xLeft > 0) xSeg.push_back(i - xLeft);
                xLeft = -1;
            }
            if (yLeft == -1) {
                yLeft = i;
            }
        }
    }
    if (yLeft != -1) {
        ans += n - yLeft - 1;
    }

    sort(xSeg.begin(), xSeg.end());
    for (const ll len : xSeg) {
        if (k >= len) {
            ans += len + 1;
            k -= len;
        } else {
            break;
        }
    }
    ans += k;
    
    cout << ans << endl;
    return 0;
}