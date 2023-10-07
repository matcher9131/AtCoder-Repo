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
    int n, m;
    cin >> n >> m;
    // point, problem No.
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<string> s(n);
    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        score[i] = i + 1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'o') score[i] += a[j].first;
        }
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int currentTop = *max_element(score.begin(), score.end());

    for (int i = 0; i < n; ++i) {
        if (score[i] == currentTop) {
            cout << 0 << endl;
        } else {
            int ans = 0;
            int t = score[i];
            for (int j = 0; j < m; ++j) {
                if (s[i][a[j].second] == 'x') {
                    ++ans;
                    t += a[j].first;
                    if (t > currentTop) {
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    

    return 0;
}