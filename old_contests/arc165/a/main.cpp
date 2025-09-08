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

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    auto judge = [](int n) {
        for (int i = 2; i * i < n; ++i) {
            if (n % i > 0) continue;
            int j = n / i;
            if (gcd(i, j) == 1) {
                cout << "Yes" << endl;
                return;
            };
        }
        cout << "No" << endl;
    };

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        judge(n);
    }

    return 0;
}