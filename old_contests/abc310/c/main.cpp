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
    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        string t, rt;
        cin >> t;
        rt = t;
        reverse(rt.begin(), rt.end());
        s.insert(rt < t ? rt : t);
    }

    cout << s.size() << endl;

    return 0;
}