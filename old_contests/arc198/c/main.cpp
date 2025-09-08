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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int currentDiff = 0;
    for (int i = 0; i < n; ++i) {
        currentDiff += abs(a[i] - b[i]);
    }

    auto change = [&]() -> int {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int newAi = a[j] - 1;
                int newAj = a[i] + 1;
                int newDiff = currentDiff - abs(a[i] - b[i]) - abs(a[j] - b[j]) + abs(newAi - b[i]) + abs(newAj + b[j]);
                if (newDiff < currentDiff) {
                    a[i] = newAi;
                    a[j] = newAj;
                    return newDiff;
                }
            }
        }
        return currentDiff;
    };

    while (currentDiff > 0) {
        int newDiff = change();
        if (newDiff == currentDiff) {
            cout << "error" << endl;
        }
        currentDiff = newDiff;
    }




    return 0;
}