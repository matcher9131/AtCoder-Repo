#include <vector>
#include <string>
using namespace std;

template<int CHAR_SIZE, int BASE>
struct Trie {
    struct Node {
        vector<int> next;
        vector<int> ids;
        int ch;
        int num_str;
        Node (int _ch) : next(CHAR_SIZE, -1) ch(_ch), num_str(0) {
        }
    };

    vector<Node> nodes;
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    void insert(const string &s, int id = nodes[0].num_str) {
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

    int num_start_with(const string &s) {
        int node_id = 0;
        for (const char c : s) {
            int ch = (int)(c - BASE);
            int next_id = nodes[node_id].next[c];
            if (next_id == -1) return 0;
            node_id = next_id;
        }
        return nodes[node_id].num_str;
    }
};