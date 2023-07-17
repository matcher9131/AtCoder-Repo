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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

bool isPrime(int num) {
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> ans{ 31, 41, 61, 71, 101 };

    for(int p = 131; ; p += 10) {
        if (ans.size() >= n) break;
        if (isPrime(p)) ans.push_back(p);
    }

    cout << ans[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}