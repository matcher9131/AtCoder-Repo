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
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == '#' && s[i+1] == '.' && s[i+2] == '#') ++ans;
    }

    cout << ans << endl;

    return 0;
}