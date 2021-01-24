// https://qiita.com/e869120/items/eb50fdaece12be418faa
// https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int val[201010];

void dfs(const Graph &G, int v, int p = -1) {
    for (auto nv : G[v]) {
        if (p != nv) {
            val[nv] += val[v];
            dfs(G, nv, v);
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    Graph G(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, q) {
        int p, x;
        cin >> p >> x;
        --p;
        val[p] += x;
    }

    dfs(G, 0);

    rep(i, n) {
        if (i) cout << " ";
        cout << val[i];
    }
    cout << endl;

    return 0;
}