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
    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    --si;
    --sj;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    string x;
    cin >> x;

    int i = si, j = sj;
    for (const char c : x) {
        if (c == 'U') {
            if (i > 0 && s[i-1][j] != '#') --i;
        } else if (c == 'D') {
            if (i < h-1 && s[i+1][j] != '#') ++i;
        } else if (c == 'L') {
            if (j > 0 && s[i][j-1] != '#') --j;
        } else if (c == 'R') {
            if (j < w - 1 && s[i][j+1] != '#') ++j;
        }
    }

    cout << i + 1 << " " << j + 1 << endl;

    return 0;
}