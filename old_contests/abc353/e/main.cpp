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

template<int CHAR_SIZE, int BASE>
struct Trie {
    struct Node {
        vector<int> next;
        vector<int> ids;
        int ch;
        int num_str;
        Node (int _ch) : next(CHAR_SIZE, -1), ch(_ch), num_str(0) {
        }
    };

    vector<Node> nodes;
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    void insert(const string &s, int id) {
        int node_id = 0;
        for (const char c : s) {
            int ch = (int)(c - BASE);
            int &next_id = nodes[node_id].next[ch];
            if (next_id == -1) {
                next_id = (int)nodes.size();
                nodes.push_back(Node(ch));
            }
            ++nodes[node_id].num_str;
            node_id = next_id;
        }
        ++nodes[node_id].num_str;
        nodes[node_id].ids.push_back(id);
    }

    int cumulative_sum_num_str(const string &s) {
        ll ans = 0;
        int node_id = 0;
        for (const char c : s) {
            int ch = (int)(c - BASE);
            int next_id = nodes[node_id].next[ch];
            if (next_id == -1) break;
            node_id = next_id;
            ans += nodes[node_id].num_str;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    Trie<26, 'a'> trie;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        trie.insert(s[i], i);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += trie.cumulative_sum_num_str(s[i]);
        ans -= (int)s[i].size();
    }
    ans /= 2;

    cout << ans << endl;
    return 0;
}