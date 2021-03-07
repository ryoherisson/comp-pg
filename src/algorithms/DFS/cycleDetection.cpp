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

vector<bool> seen, finished;

int pos = -1;
stack<int> hist;

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (auto nv : G[v]) {
        if (nv = p) continue;

        if (finished[nv]) continue;

        if (seen[nv] && !finished[nv]) {
            pos = nv;
            return;
        }

        dfs(G, nv, v);

        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    Graph G(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    finished.assign(N, false);
    pos = -1;
    dfs(G, 0, -1);

    set<int> cycle;
    while(!hist.empty()) {
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if (t == pos) break;
    }

    int Q;
    cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (cycle.count(a) && cycle.count(b)) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}