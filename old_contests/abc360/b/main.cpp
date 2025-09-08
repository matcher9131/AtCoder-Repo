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
    string s, t;
    cin >> s >> t;
    int n = s.size();

    for (int w = 1; w < n; ++w) {
        for (int c = 0; c < w; ++c) {
            string cur = "";
            for (int i = 0; i <= n / w; ++i) {
                int j = i * w + c;
                if (j < n) {
                    cur += s[i * w + c];
                }
            }
            if (cur == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}