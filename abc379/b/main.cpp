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

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'O') {
            int l = i;
            for (; i < n && s[i] == 'O'; ++i) {}
            ans += (i - l) / k;
        }
    }

    cout << ans << endl;

    return 0;
}