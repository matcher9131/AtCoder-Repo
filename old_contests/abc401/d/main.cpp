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
    int no = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if ((i > 0 && s[i-1] == 'o') || (i < n - 1 && s[i+1] == 'o')) {
                s[i] = '.';
            }
        } else if (s[i] == 'o') {
            ++no;
        }
    }

    if (no == k) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                s[i] = '.';
            }
        }
        cout << s << endl;
        return 0;
    }

    vector<pair<int, int>> seg;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            int j = i;
            for (; j < n; ++j) {
                if (s[j] != '?') break;
            }
            if (j > i) {
                seg.emplace_back(i, j);
                i = j - 1;
            }
        }
    }

    int maxPossibleO = accumulate(seg.begin(), seg.end(), 0, [](int acc, pair<int, int>& s) { return acc + (s.second - s.first + 1) / 2; }) + no;
    if (maxPossibleO == k) {
        for (const auto& [i, j] : seg) {
            if ((j - i) % 2) {
                for (int k = i; k < j; k += 2) {
                    s[k] = 'o';
                    if (k+1 < j) s[k+1] = '.';
                }
            }
        }
        cout << s << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}