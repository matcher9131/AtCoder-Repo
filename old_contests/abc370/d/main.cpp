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
    int h, w, nq;
    cin >> h >> w >> nq;
    vector<int> r(nq), c(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> r[i] >> c[i];
        --r[i];
        --c[i];
    }

    set<int> rowSet, colSet;
    for (int j = -1; j <= w; ++j) {
        rowSet.emplace_hint(rowSet.end(), j);
    }
    for (int i = -1; i <= h; ++i) {
        colSet.emplace_hint(colSet.end(), i);
    }
    vector<set<int>> rows(h, set<int>(rowSet)), cols(w, set<int>(colSet));
    
    int destroyed = 0;
    for (int qi = 0; qi < nq; ++qi) {
        int i = r[qi], j = c[qi];
        if (rows[i].contains(j)) {
            rows[i].erase(j);
            cols[j].erase(i);
            ++destroyed;
        } else {
            auto itr = rows[i].lower_bound(j);
            auto itl = itr;
            --itl;
            auto itd = cols[j].lower_bound(i);
            auto itu = itd;
            --itu;
            if (*itr < w) {
                rows[i].erase(itr);
                cols[*itr].erase(i);
                ++destroyed;
            }
            if (*itl >= 0) {
                rows[i].erase(itl);
                cols[*itl].erase(i);
                ++destroyed;
            }
            if (*itd < h) {
                cols[j].erase(itd);
                rows[*itd].erase(j);
                ++destroyed;
            }
            if (*itu >= 0) {
                cols[j].erase(itu);
                rows[*itu].erase(j);
                ++destroyed;
            }
        }
    }

    cout << h * w - destroyed << endl;

    return 0;
}