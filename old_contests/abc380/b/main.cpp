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
    string s;
    cin >> s;

    int i = 1;
    vector<int> a;
    while (true) {
        int next = s.find('|', i);
        if (next == string::npos) break;
        a.push_back(next - i);
        i = next + 1;
    }

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }

    return 0;
}