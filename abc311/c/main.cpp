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


int n;
vector<int> to;
vector<bool> pre;
int cycleRoot = -1;
void dfs(int v) {
    pre[v] = true;
    int nv = to[v];
    if (pre[nv]) {
        cycleRoot = nv;
        return;
    }
 
    dfs(nv);
    if (cycleRoot != -1) return;
}
 
int main() {
    cin >> n;
    to = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        --t;
        to[i] = t;
    }
 
    pre = vector<bool>(n);
    dfs(0);
 
    vector<int> cycle{ cycleRoot };
    for (int next = to[cycleRoot]; next != cycleRoot; next = to[next]) {
        cycle.push_back(next);
    }
 
    cout << cycle.size() << endl;
    cout << (cycle[0] + 1);
    for (int i = 1; i < cycle.size(); ++i) {
        cout << " " << (cycle[i] + 1);
    }
    cout << endl;
 
    return 0;
}