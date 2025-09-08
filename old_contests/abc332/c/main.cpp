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
    string s;
    cin >> s;

    int num1 = 0;
    int num2 = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ans = max(ans, num2);
            ans = max(ans, num1 + num2 - m);
            num1 = 0;
            num2 = 0;
        } else if (s[i] == '1') ++num1;
        else ++num2;
    }
    ans = max(ans, num2);
    ans = max(ans, num1 + num2 - m);

    cout << ans << endl;
    return 0;
}