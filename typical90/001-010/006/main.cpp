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

    vector<priority_queue<int, vector<int>, greater<int>>> ch(26);
    for (int i = 0; i < n; ++i) {
        ch[(int)(s[i] - 'a')].push(i);
    }

    string ans;
    int left = 0;
    for (int i = 0; i < k; ++i) {
        int right = n - k + i;
        for (int c = 0; c < 26; ++c) {
            int nextIndex = ([&]() {
                while (!ch[c].empty()) {
                    int j = ch[c].top();
                    if (j < left) {
                        ch[c].pop();
                    } else if (j <= right) {
                        ch[c].pop();
                        left = j + 1;
                        return j;
                    } else {
                        break;
                    }
                }
                return -1;
            })();
            if (nextIndex >= 0) {
                ans += s[nextIndex];
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}