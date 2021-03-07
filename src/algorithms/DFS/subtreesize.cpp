#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector< vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p, int d) {
    depth[v] = d;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, nv, v, d+1);
    }

    subtree_size[v] = 1;
    for (auto c : G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N; cin >> N;

    Graph G(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int root = 0;
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root, -1, 0);

    for (int v = 0; v < N; v++) {
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
    }


    return 0;
}