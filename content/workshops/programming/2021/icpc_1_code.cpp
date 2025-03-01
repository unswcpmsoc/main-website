#include <cstdio>
#include <vector>
using namespace std;

int N, M, a, b;
vector<int> adj[200005];

bool seen[200005];
bool colour[200005];

void dfs(int u) {
    seen[u] = true;
    printf("%d\n", u);
    for (int v: adj[u]) {
        
        // following if block is for 2-colouring
        if (seen[v]) {
            if (colour[u] == colour[v]) {
                printf("contradiction\n");
                exit(0);
            } else {
                continue;
            }
        }
        
        if (!seen[v]) {
            colour[v] = !colour[u]; // for 2-colouring
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b); // a= 2, b =3
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // dfs from node 1:
    dfs(1);
    
    // explore / 2-colour every component:
    for (int i = 1; i <= N; i++) {
        if (!seen[i]) dfs(i);
    }
    
}

// Sample graph.in
/*
9 8
1 2
1 5
2 5
5 4
4 3
2 3
4 6
7 8
*/