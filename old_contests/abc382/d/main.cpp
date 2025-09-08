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
#include <bitset>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    int maxBalls = m - 10 * (n - 1) - 1;

    vector<vector<int>> gaps;
    for (int balls = 0; balls <= maxBalls; ++balls) {
        int numBits = balls + n - 1;
        for (unsigned bits = 0; bits < (1U << numBits); ++bits) {
            if (popcount(bits) != balls) continue;
            vector<int> gap;
            int lp = -1;
            for (int i = 0; i < numBits; ++i) {
                if ((bits & 1U << i) == 0) {
                    gap.push_back(i - lp - 1);
                    lp = i;
                }
            }
            gap.push_back(numBits - lp - 1);
            gaps.push_back(gap);
        }
    }

    sort(gaps.begin(), gaps.end());

    cout << gaps.size() << endl;
    for (const auto& gap : gaps) {
        int last = 1 + gap[0];
        cout << last;
        for (int i = 1; i < n; ++i) {
            last += 10 + gap[i];
            cout << " " << last;
        }
        cout << endl;
    }

    return 0;
}