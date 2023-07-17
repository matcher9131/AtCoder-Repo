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

vector<int> a;

bool isOK(int maxLength, int count) {
    int s = 0;
    for (const int log : a) {
        s += (log + maxLength - 1) / maxLength - 1;
    }
    return s <= count;
}

int binary_search(int count) {
    int ng = 0;
    int ok = *max_element(a.begin(), a.end());

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, count)) ok = mid;
        else ng = mid;
    }
    
    return ok;
}

int main() {
    int n, k;
    cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int answer = binary_search(k);

    cout << answer << endl;

    return 0;
}