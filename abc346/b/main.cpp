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
    int w, b;
    cin >> w >> b;
    string s0 = "wbwbwwbwbwbw";
    string s = "";
    for (int i = 0; i < 18; ++i) {
        s += s0;
    }
    int n = s.size();
    vector<int> sw(n+1), sb(n+1);
    for (int i = 0; i < n; ++i) {
        sw[i+1] = sw[i] + (s[i] == 'w' ? 1 : 0);
        sb[i+1] = sb[i] + (s[i] == 'b' ? 1 : 0);
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (sw[j] - sw[i] == w && sb[j] - sb[i] == b) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}