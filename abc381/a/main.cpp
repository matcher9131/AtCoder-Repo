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

    if (n % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        if (s[i] != '1' || s[n-1-i] != '2') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s[m] == '/') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}