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

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = n; i > 0; --i) {
        for (int j = 0; j <= n - i; ++j) {
            if (isPalindrome(s.substr(j, i))) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}
