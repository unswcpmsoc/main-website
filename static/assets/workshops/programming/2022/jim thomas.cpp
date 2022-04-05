#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long ll;

ll N, Q;
vector<pair<ll, ll>> routes[100005];
ll height[100005], dist[100005], jump[100005][20];

// for this node, and all of its subtree, set the values of dist, height and jump[0]
void dfs(ll node, ll parent, ll h = 0, ll d = 0) {
    height[node] = h;
    dist[node] = d;
    jump[node][0] = parent;
    for (pair<ll, ll> next : routes[node]) {
        ll newDist = next.first;
        ll child = next.second;
        // check whether this is a new node we havent seen
        // we dont want to go to the parent node
        if (child != parent) {
            dfs(child, node, h + 1, d + newDist);
        }
    }
}

// find the lca of nodes a and b
ll lca(ll a, ll b) {
    // jump from a, b until they are at same height
    // try really big jumps, then increasingly smaller jumps
    for (ll j = 19; j >= 0; --j) {
        if (height[jump[a][j]] >= height[b]) {
            // jump from a if it doesnt "overtake" b
            a = jump[a][j];
        }
        if (height[jump[b][j]] >= height[a]) {
            // jump from b if it doesnt "overtake" a
            b = jump[b][j];
        }
    }

    assert(height[a] == height[b]);

    // maybe they are now the same node
    // in that case, this is the lca
    if (a == b) {
        return a;
    }

    // otherwise, lets continue jumping
    for (ll j = 19; j >= 0; --j) {
        if (jump[a][j] != jump[b][j]) {
            a = jump[a][j];
            b = jump[b][j];
        }
    }

    assert(jump[a][0] == jump[b][0]);
    return jump[a][0];
}

int main() {
    ifstream fin{ "jim.in" };
    ofstream fout{ "jim.out" };
    fin >> N >> Q;
    ll a, b, d;
    for (ll i = 0; i < N - 1; ++i) {
        fin >> a >> b >> d;
        routes[a].push_back({ d, b });
        routes[b].push_back({ d, a });
    }

    // root tree arbitarily at node 1
    // for simplicity, 1 is its own parent
    dfs(1, 1);

    // jump[node][j] holds the (2^j)th parent of node
    // as such, jump[node][0] hold the immediate parent
    // jump[node][19] is the root, which is node 1
    for (ll j = 0; j < 19; ++j) {
        for (ll node = 1; node <= N; ++node) {
            // (2^j)th parent = jump[node][j]
            // (2 * 2^j)th parent = (2^j)th parent of (2^j)th parent = jump[(2^j)th parent][j]
            jump[node][j + 1] = jump[jump[node][j]][j];
        }
    }

    for (ll i = 0; i < Q; ++i) {
        fin >> a >> b;
        ll c = lca(a, b);
        // distance is the sum of the 2 branches
        fout << (dist[a] - dist[c]) + (dist[b] - dist[c]) << "\n";
    }
}