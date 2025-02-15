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
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == 'B') {
                    int k = 2 * j - i;
                    if (k < n && s[k] == 'C') ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}