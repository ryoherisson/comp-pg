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

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N; cin >> N;

    Graph G(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
        ++deg.at(a), ++deg.at(b);
    }

    queue<int> que;
    for (int v = 0; v < N; v++) if (deg[v] == 1) que.push(v);

    vector<bool> ispushed(N, false);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        ispushed.at(v) = true;
        for (auto nv : G.at(v)) {
            --deg.at(nv);
            if (deg.at(nv) == 1) que.push(nv);
        }
    }

    int Q; cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int a, b; cin >> a >> b; --a; --b;
        if (!ispushed.at(a) && !ispushed.at(b)) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}