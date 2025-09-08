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
    void insert(const string &s) {
        insert(s, nodes[0].num_str);
    }

    bool contains_prefix_of(const string &s) {
        int node_id = 0;
        for (const char c : s) {
            if (nodes[node_id].ids.size() > 0) return true;
            int ch = (int)(c - BASE);
            int next_id = nodes[node_id].next[ch];
            if (next_id == -1) return false;
            node_id = next_id;
        }
        return nodes[node_id].ids.size() > 0;
    }

    void remove_start_with(const string &s) {
        int node_id = 0;
        for (const char c : s) {
            int ch = (int)(c - BASE);
            int next_id = nodes[node_id].next[ch];
            if (next_id == -1) return;
            node_id = next_id;
        }
        int num_removed = nodes[node_id].num_str;
        int last_node_id = node_id;
        
        node_id = 0;
        for (const char c : s) {
            nodes[node_id].num_str -= num_removed;
            int ch = (int)(c - BASE);
            int next_id = nodes[node_id].next[ch];
            if (next_id == -1) return;
            if (next_id == last_node_id) {
                nodes[node_id].next[ch] = -1;
            }
            node_id = next_id;
        }
        nodes[node_id].next.assign(CHAR_SIZE, -1);
        nodes[node_id].ids.clear();

        //
        // for (const auto &node : nodes) {
        //     printf("ch = %d, ids.size() = %d, num_str = %d\n", node.ch, (int)node.ids.size(), node.num_str);
        // }
        //
    }

    int size() {
        return nodes[0].num_str;
    }
};

int main() {
    int nq;
    cin >> nq;

    Trie<26, 'a'> xt;
    Trie<26, 'a'> yt;

    while (nq--) {
        int k;
        string s;
        cin >> k >> s;
        if (k == 1) {
            xt.insert(s);
            yt.remove_start_with(s);
            cout << yt.size() << endl;
        } else {
            if (!xt.contains_prefix_of(s)) {
                yt.insert(s);
            }
            cout << yt.size() << endl;
        }
    }

    return 0;
}