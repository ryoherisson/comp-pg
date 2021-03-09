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

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {};

    void init(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return par[root(x)];
    }

};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(n);

    rep(i, m) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    UnionFind uf(n);

    int res = 0;
    rep(i, m) {
        uf.init(n);
        rep(j, m) {
            if (i == j) continue;
            uf.unite(a[j], b[j]);
        }
        if (uf.size(0) != n) res++;
    }

    cout << res << endl;

    return 0;
}