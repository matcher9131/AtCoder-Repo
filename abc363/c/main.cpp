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
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());

    auto isPalindrome = [&](int k) -> bool {
        for (int i = 0; i < n - k + 1; ++i) {
            bool b = true;
            for (int j = 0; j < k / 2; ++j) {
                assert(i + j < n);
                assert(i + k - 1 - j < n);
                assert(i + k - 1 - j >= 0);
                if (s[i + j] != s[i + k - 1 - j]) {
                    b = false;
                    break;
                }
            }
            if (b) return true;
        }
        return false;
    };

    int ans = 0;
    do {
        if (!isPalindrome(k)) ++ans;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;

    return 0;
}