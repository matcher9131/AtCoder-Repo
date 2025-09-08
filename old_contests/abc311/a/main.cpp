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


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool a = false, b = false, c = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a = true;
        if (s[i] == 'B') b = true;
        if (s[i] == 'C') c = true;
        if (a && b && c) {
            cout << (i + 1) << endl;
            return 0;
        }
    }

    return 0;
}