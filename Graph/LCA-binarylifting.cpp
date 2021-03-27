#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
class LCA {
 public:
  vi in, out;
  vi *adj;
  vvi dp;
  int c, timer, n;
  // c is the maximum jump we can take in binary lifting
  // timer is variable to get in time and out time of each node
  LCA(int n1, vi *adj1, int root) {
    n = n1;
    adj = adj1;
    preprocess(root);
  }
  int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = c; i >= 0; i--) {
      if (is_ancestor(dp[u][i], v) == is_ancestor(u, v)) u = dp[u][i];
    }
    return dp[u][0];
  }

 private:
  void dfs(int u, int p) {
    in[u] = timer++;
    dp[u][0] = p;
    for (int i = 1; i <= c; i++) {
      dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto v : adj[u]) {
      if (v != p) dfs(v, u);
    }
    out[u] = timer++;
  }
  bool is_ancestor(int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; }
  void preprocess(int root) {
    c = ceil(log2(n)) + 1;
    timer = 1;
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    dp.resize(n + 1, vi(c + 1, 0));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= c; j++) dp[i][j] = 0;
    }
    dfs(root, root);
  }
};

/*
create Lca object
With Constructor consisiting of n(number of nodes) , adj(adjacency list ofour
tree),root

example craetion of object

LCA tree = LCA(n, adj, root);

for lca query

int node1,node2;
cout << tree.lca(node1, node2) << "\n";
this is will give
*/
