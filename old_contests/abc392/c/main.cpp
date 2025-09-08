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
    // index, looking
    unordered_map<int, int> looking;
    // index, bib
    unordered_map<int, int> bib;
    // bib, index
    unordered_map<int, int> revBib;
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        --pi;
        looking.emplace(i, pi);
    }
    for (int i = 0; i < n; ++i) {
        int qi;
        cin >> qi;
        --qi;
        bib.emplace(i, qi);
        revBib.emplace(qi, i);
    }

    for (int i = 0; i < n; ++i) {
        cout << bib[looking[revBib[i]]] + 1 << " \n"[i == n - 1];
    }

    return 0;
}