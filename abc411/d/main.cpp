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
    int n, nq;
    cin >> n >> nq;

    vector<string> s;
    s.push_back("");
    vector<int> parent;
    parent.push_back(-1);
    vector<int> pc(n+1); 
    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int p;
            cin >> p;
            pc[p] = pc[0];
        } else if (k == 2) {
            int p;
            string ns;
            cin >> p >> ns;
            s.push_back(ns);
            parent.push_back(pc[p]);
            pc[p] = (int)s.size() - 1;
        } else {
            int p;
            cin >> p;
            pc[0] = pc[p];
        }
    }

    vector<int> path;
    for (int current = pc[0]; current >= 0; current = parent[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());

    string ans = "";
    for (const int v : path) {
        ans += s[v];
    }

    cout << ans << endl;
    return 0;
}