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

ll powll(ll x, int y) {
    ll ans = 1;
    for (int i = 0; i < y; ++i) {
        ans *= x;
    }
    return ans;
}

// k桁のヘビ数の個数
ll snakeK(int k) {
    ll ans = 0;
    for (ll i = 1; i <= 9; ++i) {
        ll p = 1;
        ans += powll(i, k - 1);
    }
    return ans;
}

// x以下のヘビ数の個数
ll snake(ll x) {
    vector<ll> digits;
    ll q = x;
    while (true) {
        digits.push_back(q % 10);
        q /= 10;
        if (q == 0) break;
    }
    reverse(digits.begin(), digits.end());
    
    ll ans = 0LL;
    // xの桁数未満のヘビ数
    for (int k = 1; k < digits.size(); ++k) {
        ans += snakeK(k);
    }
    // xの桁数と一致し先頭がxの先頭より小さいヘビ数
    for (int i = 1; i < digits[0]; ++i) {
        ans += powll(i, digits.size() - 1);
    }
    
    // xの桁数と一致し先頭がxの先頭と一致するヘビ数
    ll n = digits[0];
    for (int i = 1; i < digits.size(); ++i) {
        // 先頭以外の桁を上から順番見て、n以上が出てきたら以降すべてをn-1に書き換える
        // これをn進数と見れば個数がわかる
        if (digits[i] >= n) {
            for (int j = i; j < digits.size(); ++j) {
                digits[j] = n - 1;
            }
            break;
        }
    }
    digits[0] = 0LL;
    ll sum = 0LL;
    for (int i = 0; i < digits.size(); ++i) {
        sum *= n;
        sum += digits[i];
    }
    ans += sum + 1;

    return ans;
}

int main() {
    ll l, r;
    cin >> l >> r;

    cout << snake(r) - snake(l-1) << endl;

    return 0;
}