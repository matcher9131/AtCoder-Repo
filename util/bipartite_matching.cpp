#include <vector>
#include <unordered_set>
using namespace std;

class BipartiteMatching {
    int _an, _bn;
    vector<vector<int>> _edge;
    bool _dfs(int ai, unordered_set<int> &visited, vector<int> &matched) {
        for (const int bi : _edge[ai]) {
            if (visited.contains(bi)) continue;
            visited.insert(bi);
            if (matched[bi] == -1 || _dfs(matched[bi], visited, matched)) {
                matched[bi] = ai;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteMatching(int an, int bn) : _an(an), _bn(bn), _edge(_an, vector<int>()) {}
    void add_edge(int ai, int bi) {
        _edge[ai].push_back(bi);
    }
    int solve() {
        vector<int> matched(_bn, -1);
        int ans = 0;
        for (int i = 0; i < _an; ++i) {
            unordered_set<int> visited;
            visited.reserve(_bn);
            ans += (int)_dfs(i, visited, matched);
        }
        return ans;
    } 
};