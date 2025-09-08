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
    int n, nq;
    string s;
    cin >> n >> nq >> s;
    vector<int> x(nq);
    vector<char> c(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> x[i] >> c[i];
        --x[i];
    }

    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ++ans;
    }

    for (int qi = 0; qi < nq; ++qi) {
        int i = x[qi];
        char ch = c[qi];
        if (i + 2 < n && s[i+1] == 'B' && s[i+2] == 'C') {
            if (s[i] == 'A') --ans;
            if (ch == 'A') ++ans;
        }
        if (i - 1 >= 0 && i + 1 < n && s[i-1] == 'A' && s[i+1] == 'C') {
            if (s[i] == 'B') --ans;
            if (ch == 'B') ++ans;
        }
        if (i - 2 >= 0 && s[i-2] == 'A' && s[i-1] == 'B') {
            if (s[i] == 'C') --ans;
            if (ch == 'C') ++ans;
        }
        s[i] = ch;
        cout << ans << endl;
    }

    return 0;
}