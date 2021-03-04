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

    int N, M; cin >> N >> M;

    Graph G(N);
    vector<int> deg(N, 0); // 各頂点の出次数
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        deg[a]++;
    }

    // シンクをqueueへ
    queue<int> que;
    for (int i = 0; i < N; i++) if (deg.at(i) == 0) que.push(i);

    vector<int> order;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        order.push_back(v);

        for (auto nv : G.at(v)) {
            --deg.at(nv);

            if (deg.at(nv) == 0) que.push(nv);
        }

    }

    reverse(order.begin(), order.end());
    for (auto v : order) cout << v << endl;

    return 0;
}