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

vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen.at(v) = true;

    for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        dfs(G, nv);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
    }

    seen.assign(N, false);
    dfs(G, s);

    if (seen.at(t)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}