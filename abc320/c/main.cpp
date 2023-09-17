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

constexpr int INF = 1000;

int main() {
    int m;
    cin >> m;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; ++i) {
        s[i] += s[i] + s[i];
    }

    int ans = INF;
    vector<int> perm{ 0, 1, 2 };
    do {
        for (int d = 0; d < 10; ++d) {
            int ansd = ([&](int d) {
                int j = -1;
                for (const int i : perm) {
                    j = s[i].find('0' + (char)d, j + 1);
                    if (j == -1) return INF;
                }
                return j;
            })(d);
            ans = min(ans, ansd);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}