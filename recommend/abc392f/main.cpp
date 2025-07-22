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


template <class T>
class SplayTree {
private:
    struct Node {
        T val;
        size_t size;
        Node *left, *right, *parent;

        Node(T v): val(v), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root = nullptr;

    static size_t get_size(Node *x) {
        return x != nullptr ? x->size : 0;
    }

    static void update_node(Node *x) {
        if (x == nullptr) return;
        x->size = 1 + get_size(x->left) + get_size(x->right);
        if (x->left != nullptr) x->left->parent = x;
        if (x->right != nullptr) x->right->parent = x;
    }

    static void rotate(Node *&root, Node *x) {
        Node *p = x->parent;
        Node *g = p->parent;
        if (p->left == x) {
            p->left = x->right;
            x->right = p;
        } else {
            p->right = x->left;
            x->left = p;
        }
        update_node(p);
        update_node(x);
        x->parent = g;
        if (g != nullptr) {
            if (g->left == p) g->left = x;
            else g->right = x;
        } else {
            root = x;
        }
    }
    static void splay(Node *&root, Node *x) {
        while (x->parent != nullptr) {
            Node *p = x->parent;
            Node *g = p->parent;
            if (g == nullptr) {
                rotate(root, x);
            } else if ((g->left == p) == (p->left == x)) {
                rotate(root, p);
                rotate(root, x);
            } else {
                rotate(root, x);
                rotate(root, x);
            }
        }
    }

    Node *find_kth(size_t k) {
        Node *x = root;
        while (x != nullptr) {
            size_t left_size = get_size(x->left);
            if (k < left_size) {
                x = x->left;
            } else if (k > left_size) {
                k -= left_size + 1;
                x = x->right;
            } else {
                splay(root, x);
                return x;
            }
        }
        return nullptr;
    }

    Node *merge(Node *left, Node *right) {
        if (left == nullptr) return right;
        Node *max_left = left;
        while (max_left->right != nullptr) max_left = max_left->right;
        splay(left, max_left);
        left->right = right;
        update_node(left);
        return left;
    }

public:
    T get_kth(size_t k) {
        Node *x = find_kth(k);
        assert(x != nullptr);
        return x->val;
    }

    void insert(size_t k, T val) {
        Node *new_node = new Node(val);
        if (root == nullptr) {
            root = new_node;
            return;
        }
        if (get_size(root) == k) {
            new_node->left = root;
            root->parent = new_node;
            update_node(new_node);
            root = new_node;
        } else {
            new_node->left = root->left;
            new_node->right = root;
            root->left = nullptr;
            update_node(root);
            update_node(new_node);
            root = new_node;
        }
    }

    void erase(size_t k) {
        Node* x = find_kth(k);
        if (x == nullptr) return;

        Node *left = x->left;
        Node *right = x->right;
        if (left != nullptr) left->parent = nullptr;
        if (right != nullptr) right->parent = nullptr;

        root = merge(left, right);
    }
};


int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    SplayTree<ll> st;
    for (ll i = 0; i < n; ++i) {
        st.insert(i, i);
    }
    vector<ll> ans(n);
    for (ll i = n - 1; i >= 0; --i) {
        ans[st.get_kth(p[i])] = i;
        st.erase(p[i]);
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}