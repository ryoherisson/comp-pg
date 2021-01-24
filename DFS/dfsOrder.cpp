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

vector<bool> seen;
vector<int> first_order;
vector<int> last_order;

void dfs(const Graph &G, int v, int& first_ptr) {
    first_order[v] = first_ptr++;
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv, first_ptr);
    }
    last_order[v] = first_ptr++;
}


int main()
{
    int n;
    cin >> n;
    Graph G(n+1);
    rep(i, n) {
        int u, k;
        cin >> u >> k;
        u;
        rep(j, k) {
            int v;
            cin >> v;
            v;
            G[u].push_back(v);
        }
        sort(G[u].begin(), G[u].end());
    }

    seen.assign(n+1, false);
    first_order.resize(n+1);
    last_order.resize(n+1);
    int first_ptr = 1;
    dfs(G, 1, first_ptr);

    REP(v, 1, n+1) {
        cout << v << " " << first_order[v] << " " << last_order[v] << endl;
    }

    return 0;
}